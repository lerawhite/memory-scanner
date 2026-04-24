\# Windows Process Inspector \& Memory Scanner



\## 📌 Overview



This project is a low-level Windows tool designed for:



\* Process enumeration and inspection

\* Token privilege and integrity level analysis
\* Basic memory injection using WinAPI

\* Remote memory scanning for byte/string patterns





The goal of this project is to explore and demonstrate how user-mode applications interact with process memory and Windows internals.



\---



\## ⚙️ Features



\### 🔍 Process Inspection



\* Enumerate all running processes using `CreateToolhelp32Snapshot`

\* Filter processes by name

\* Display PID, PPID, and thread count



\### 🔐 Token Analysis



\* Retrieve process token

\* Extract:



 \* SID (Security Identifier)

 \* Integrity Level (Low / Medium / High / System)



\### 💉 Memory Injection



\* Allocate memory in a remote process (`VirtualAllocEx`)

\* Write arbitrary string into process memory (`WriteProcessMemory`)

\* Optional injection into user-defined address



\### 🧠 Memory Scanner



\* Iterates through the full user-mode Virtual Address Space (VAS)

\* Uses `VirtualQueryEx` to enumerate memory regions

\* Filters readable and committed regions

\* Reads memory using `ReadProcessMemory`

\* Performs byte-pattern search



\---



\## 🏗️ Architecture



The project follows a layered architecture:



```

L4 - Application / UI Layer

   - User interaction

   - Scenario orchestration



L3 - Workflow Layer

   - High-level logic (memory scanning pipeline)



L2 - Operation Layer

   - Process, memory, and security operations



L1 - Core Layer

   - Thin wrappers over WinAPI

   - Utilities (RAII handle, memory read, etc.)



Domain Layer

   - Data structures (processinfo, memory\_region, scan\_hit, token\_info)

```



\---



\## 🧪 Example Workflow



1\. List processes

2\. Filter by name

3\. Inspect token (SID / Integrity Level)

4\. Inject string into process memory

5\. Scan process memory for a pattern



\---



\## ⚠️ Limitations (v1)



This is a first version of the tool and includes several known limitations:



\* Naive pattern search algorithm (O(n\*m))

\* No buffer overlap handling between memory chunks

\* No wildcard pattern support

\* Single-threaded scanning

\* Minimal error handling and logging



\---



\## 🚀 Roadmap (v2)



Planned improvements:



\* \[ ] Implement overlap-safe scanning

\* \[ ] Optimize pattern search (Boyer-Moore / SIMD)

\* \[ ] Add wildcard pattern support

\* \[ ] Introduce multi-threaded scanning

\* \[ ] Improve error handling and logging system

\* \[ ] Safer injection (validation + cleanup)



\---



\## 🛠️ Technologies



\* C++ (WinAPI)

\* Windows Internals:



 \* Virtual Memory (VAS)

 \* Process Environment

 \* Access Tokens

\* Tools used during development:



 \* x64dbg

 \* Visual Studio



\---



\## 🎯 Purpose



This project is part of my learning path in:



\* Low-level C++ development

\* Windows internals

\* Malware analysis \& reverse engineering



\---



\## ⚠️ Disclaimer



This project is intended for \*\*educational purposes only\*\*.



It demonstrates techniques commonly used in:



\* debugging tools

\* security research

\* malware analysis



Do not use it on systems or processes without permission.



\---

\## 👤 Author

     lerawhite



