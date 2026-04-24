
#include "core(l1)\security\get_token_rights.h"

HANDLE open_process_token(HANDLE hprocess)
{
	HANDLE htoken;
	if (hprocess == nullptr)
		return nullptr;

	if (OpenProcessToken(hprocess, TOKEN_QUERY, &htoken))
		return htoken;
	else
		return nullptr;
}



std::string get_SID(HANDLE htoken)
{
	std::string answer = "Token_info_denied\n\n";
	DWORD size = 0;
	GetTokenInformation(htoken, TokenUser, NULL, 0, &size);

	LPVOID buffer = malloc(size);
	if (!buffer)
		return answer;

	if (!GetTokenInformation(htoken, TokenUser, buffer, size, &size))
	{
		free(buffer);
		return answer;
	}

	TOKEN_USER* token_user = (TOKEN_USER*)buffer;
	LPSTR sidStr = nullptr;

	if (!ConvertSidToStringSidA(token_user->User.Sid, &sidStr))
	{
		free(buffer);
		if (sidStr) LocalFree(sidStr);
		return answer;
	}

	std::string result(sidStr);
	free(buffer);
	LocalFree(sidStr);
	return result;
}


std::string get_IL(HANDLE htoken)
{
	DWORD size = 0;
	std::string answer = "Token_info_denied\n\n";

	GetTokenInformation(htoken, TokenIntegrityLevel, NULL, 0, &size);

	LPVOID buffer = malloc(size);

	if (!GetTokenInformation(htoken, TokenIntegrityLevel, buffer, size, &size))
	{
		free(buffer);
		return answer;
	}

	TOKEN_MANDATORY_LABEL* til = (TOKEN_MANDATORY_LABEL*)buffer;

	DWORD rid = *GetSidSubAuthority(til->Label.Sid, *GetSidSubAuthorityCount(til->Label.Sid) - 1);
	free(buffer);
	if (rid == SECURITY_MANDATORY_LOW_RID) return "Low";
	if (rid == SECURITY_MANDATORY_MEDIUM_RID) return "Medium";
	if (rid == SECURITY_MANDATORY_HIGH_RID) return "High";
	if (rid == SECURITY_MANDATORY_SYSTEM_RID) return "System";

	return "Unknown";
}