void MemoryErrorMain(FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[SIZE] = {}, Title[SIZE] = {};
	
	char Operate[SIZE] = "0x00000000";
	char Address[SIZE] = "0x00000000";
	char CannotBe[SIZE] = "read";
	char ErrorProgram[SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s%s%s", Operate, Address, CannotBe, ErrorProgram);
	sprintf(Text, "\"%s\" ָ�����õ� \"%s\" �ڴ档���ڴ治��Ϊ \"%s\"��\n\nҪ��ֹ�����뵥����ȷ������\nҪ���Գ����뵥����ȡ������", Operate, Address, CannotBe);
	sprintf(Title, "%s - Ӧ�ó������", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	WriteLog(LogWriter, StartTime, EndTime, "MEMORY_ERROR", Text, Title, UserChoose);
}
