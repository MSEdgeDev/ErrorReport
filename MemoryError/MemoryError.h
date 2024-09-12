SYSTEMTIME StartTime, EndTime;

void GetFormatTime(SYSTEMTIME Time, char* TimeString) {
	sprintf(TimeString, "%04d/%02d/%02d %02d:%02d:%02d.%03d",
		Time.wYear, Time.wMonth, Time.wDay, Time.wHour, 
		Time.wMinute, Time.wSecond, Time.wMilliseconds
	);
} 

void MemoryErrorMain(SYSTEMTIME MainStartTime, FILE* ConfigFileReader, FILE* LogWriter) {
	GetLocalTime(&StartTime);
	
	char Text[MAX_ARRAY_SIZE] = {}, Title[MAX_ARRAY_SIZE] = {};
	
	char Operate[MAX_ARRAY_SIZE] = "0x00000000";
	char Address[MAX_ARRAY_SIZE] = "0x00000000";
	char CannotBe[MAX_ARRAY_SIZE] = "read";
	char ErrorProgram[MAX_ARRAY_SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s%s%s", Operate, Address, CannotBe, ErrorProgram);
	sprintf(Text, "\"%s\" ָ�����õ� \"%s\" �ڴ档���ڴ治��Ϊ \"%s\"��\n\nҪ��ֹ�����뵥����ȷ������\nҪ���Գ����뵥����ȡ������", Operate, Address, CannotBe);
	sprintf(Title, "%s - Ӧ�ó������", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	char MainStartTimeString[MAX_ARRAY_SIZE], StartTimeString[MAX_ARRAY_SIZE], EndTimeString[MAX_ARRAY_SIZE];
	GetFormatTime(MainStartTime, MainStartTimeString);
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "������ʼ������ %s��\n", MainStartTimeString);
	fprintf(LogWriter, "���ε����Ĵ�������Ϊ MEMORY_ERROR��\n");
	fprintf(LogWriter, "���ڿ�ʼ׼�������� %s��\n", StartTimeString);
	fprintf(LogWriter, "���ڱ��ر��� %s��\n", EndTimeString);
	fprintf(LogWriter, "������ʾ����ϢΪ��\n%s\n", Text);
	fprintf(LogWriter, "������ʾ�ı���Ϊ��%s\n", Title);
	fprintf(LogWriter, "�û����µİ�ťΪ��%d����1 Ϊ��ȷ������2 Ϊ��ȡ������\n", UserChoose);	
	fprintf(LogWriter, "\n------\n\n");
}
