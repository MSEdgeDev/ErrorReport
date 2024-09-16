void ExeErrorMain(FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[SIZE] = {}, Title[SIZE] = {};
	
	char ErrorName[SIZE] = "unknown software exception";
	char ErrorCode[SIZE] = "0x00000000";
	char Address[SIZE] = "0x0000000000000000";
	char ErrorProgram[SIZE] = "svchost.exe"; 
	
//	fscanf(ConfigFileReader, "%s%s%s%s", ErrorName, ErrorCode, Address, ErrorProgram);
	sprintf(Text, "Ӧ�ó������쳣 %s (%s)��λ��Ϊ %s��\n\nҪ��ֹ�����뵥����ȷ������\nҪ���Գ����뵥����ȡ������", ErrorName, ErrorCode, Address);
	sprintf(Title, "%s - Ӧ�ó������", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	WriteLog(LogWriter, StartTime, EndTime, "EXE_ERROR", Text, Title, UserChoose);
}
