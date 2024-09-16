#include <Windows.h>
#include <string.h>

#define SIZE 255

#define CONFIG_FILENAME "Config.ini"
#define LOG_FILENAME "ErrorReportLog.log"

#define MEMORY_ERROR 1
#define DLL_MISSING_ERROR 2
#define EXE_ERROR 3 

#define DEFAULT_ERROR MEMORY_ERROR

char ButtonPressType[SIZE][SIZE];
char IconType[SIZE][SIZE];
char ButtonType[SIZE][SIZE];

void initTypeString() {
	strcpy(ButtonPressType[IDOK], "ȷ��");
	strcpy(ButtonPressType[IDCANCEL], "ȡ��");
	strcpy(ButtonPressType[IDABORT], "��ֹ");
	strcpy(ButtonPressType[IDRETRY], "����");
	strcpy(ButtonPressType[IDIGNORE], "����");
	strcpy(ButtonPressType[IDYES], "��");
	strcpy(ButtonPressType[IDNO], "��");
	strcpy(ButtonPressType[IDTRYAGAIN], "����");
	strcpy(ButtonPressType[IDCONTINUE], "����");
}
