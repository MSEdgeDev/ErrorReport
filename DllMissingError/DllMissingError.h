void DllMissingErrorMain(FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[SIZE] = {}, Title[SIZE] = {};
	
	char MissingDll[SIZE] = "coredpus.dll";
	char ErrorProgram[SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s", MissingDll, ErrorProgram);
	sprintf(Text, "�޷������˳�����Ϊ������ж�ʧ %s���������°�װ�ó����Խ�������⡣", MissingDll);
	sprintf(Title, "%s - ϵͳ����", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OK + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	WriteLog(LogWriter, StartTime, EndTime, "DLL_MISSING_ERROR", Text, Title, UserChoose);
}
