
#include "core(l1)\process\convert.h"

processinfo convert(const PROCESSENTRY32W& pe)
{
	processinfo p;
	p.name = pe.szExeFile;
	p.pid = (uint32_t)pe.th32ProcessID;
	p.ppid = (uint32_t)pe.th32ParentProcessID;
	p.cthread = (uint32_t)pe.cntThreads;
	return p;
}