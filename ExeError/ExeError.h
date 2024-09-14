void ExeErrorMain(SYSTEMTIME MainStartTime, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[MAX_ARRAY_SIZE] = {}, Title[MAX_ARRAY_SIZE] = {};
	
	char ErrorName[MAX_ARRAY_SIZE] = "unknown software exception";
	char ErrorCode[MAX_ARRAY_SIZE] = "0x00000000";
	char Address[MAX_ARRAY_SIZE] = "0x0000000000000000";
	char ErrorProgram[MAX_ARRAY_SIZE] = "svchost.exe"; 
	
//	fscanf(ConfigFileReader, "%s%s%s%s", ErrorName, ErrorCode, Address, ErrorProgram);
	sprintf(Text, "Ӧ�ó������쳣 %s (%s)��λ��Ϊ %s��\n\nҪ��ֹ�����뵥����ȷ������\nҪ���Գ����뵥����ȡ������", ErrorName, ErrorCode, Address);
	sprintf(Title, "%s - Ӧ�ó������", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	char MainStartTimeString[MAX_ARRAY_SIZE], StartTimeString[MAX_ARRAY_SIZE], EndTimeString[MAX_ARRAY_SIZE];
	GetFormatTime(MainStartTime, MainStartTimeString);
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "������ʼ������ %s��\n", MainStartTimeString);
	fprintf(LogWriter, "���ε����Ĵ�������Ϊ EXE_ERROR��\n");
	fprintf(LogWriter, "���ڿ�ʼ׼�������� %s��\n", StartTimeString);
	fprintf(LogWriter, "���ڱ��ر��� %s��\n", EndTimeString);
	fprintf(LogWriter, "������ʾ����ϢΪ��\n%s\n", Text);
	fprintf(LogWriter, "������ʾ�ı���Ϊ��%s\n", Title);
	fprintf(LogWriter, "�û����µİ�ťΪ��%d����1 Ϊ��ȷ������2 Ϊ��ȡ������\n", UserChoose);	
	fprintf(LogWriter, "\n------\n\n");
}
