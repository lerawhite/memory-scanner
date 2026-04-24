


#include "workflow(l3)\memory\scan_process_memory.h"



std::vector <scan_hit> scan_process_memory(DWORD pid, const std::string& scan_string)
{

	std::vector<scan_hit> v_hit{};

	uniquehandle handle(open_to_check_read(pid));

	if (!handle.get())
	{
		std::cout << std::endl << "error with open_process_rights " << std::endl; return v_hit;
	}

	SYSTEM_INFO si;
	GetSystemInfo(&si);

	BYTE* base_user_vas = (BYTE*)si.lpMinimumApplicationAddress;
	BYTE* max_user_vas = (BYTE*)si.lpMaximumApplicationAddress;


	BYTE buffer[4096];
	
	
	while (base_user_vas <= max_user_vas)
	{

		std::optional<memory_region> reg;

		reg = query_memory_reg(handle.get(), base_user_vas);

		if (!reg )
		{
			std::cout << std::endl << "error with virt_query " << std::endl <<"type of error is: " << GetLastError()  << std::endl << std::endl;
			break;
		} 

		if (reg->reg_size == 0) break;


		BYTE* base_of_region = (BYTE*)reg->adr;

		if (reg->state == MEM_COMMIT && is_readable(reg->protect))
		{
			BYTE* base_of_region_max = base_of_region + reg->reg_size;


			const BYTE* pattern = reinterpret_cast<const BYTE*>(scan_string.data());
			SIZE_T string_size = scan_string.size();

			while (base_of_region < base_of_region_max)
			{
				SIZE_T out_read = 0;
				SIZE_T remaining = base_of_region_max - base_of_region;
				SIZE_T to_read = (remaining < 4096) ? remaining : 4096;


				if (!read_memory(handle.get(), base_of_region, buffer, to_read, out_read))
				{
					std::cout << std::endl << "error with read_memory " << GetLastError() << std::endl << std::endl;
					base_of_region += to_read;
					continue;

				}


				auto offsets = search_byte_pattern(buffer, out_read, pattern, string_size);

				for (auto& offset : offsets)
				{
					

					scan_hit hit;
					hit.adr = base_of_region + offset;
					hit.scan_string = scan_string;
					hit.region.adr = reg->adr;
					hit.region.protect = reg->protect;
					hit.region.reg_size = reg->reg_size;
					hit.region.state = reg->state;
					hit.region.type = reg->type;


					v_hit.push_back(hit); //gerz
				}


				base_of_region += to_read;
			}
		}
		base_user_vas = (BYTE*)reg->adr + reg->reg_size;
	}
	return v_hit;

}