void DllMissingErrorMain(SYSTEMTIME MainStartTime, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);
	
	char Text[MAX_ARRAY_SIZE] = {}, Title[MAX_ARRAY_SIZE] = {};
	
	char MissingDll[MAX_ARRAY_SIZE] = "coredpus.dll";
	char ErrorProgram[MAX_ARRAY_SIZE] = "svchost.exe"; 
	
	fscanf(ConfigFileReader, "%s%s", MissingDll, ErrorProgram);
	sprintf(Text, "�޷������˳�����Ϊ������ж�ʧ %s���������°�װ�ó����Խ�������⡣", MissingDll);
	sprintf(Title, "%s - ϵͳ����", ErrorProgram);
	
	int UserChoose = MessageBox(NULL, Text, Title, MB_OK + MB_ICONERROR);
	
	GetLocalTime(&EndTime);
	
	char MainStartTimeString[MAX_ARRAY_SIZE], StartTimeString[MAX_ARRAY_SIZE], EndTimeString[MAX_ARRAY_SIZE];
	GetFormatTime(MainStartTime, MainStartTimeString);
	GetFormatTime(StartTime, StartTimeString); 
	GetFormatTime(EndTime, EndTimeString);
	
	fprintf(LogWriter, "������ʼ������ %s��\n", MainStartTimeString);
	fprintf(LogWriter, "���ε����Ĵ�������Ϊ DLL_MISSING_ERROR��\n");
	fprintf(LogWriter, "���ڿ�ʼ׼�������� %s��\n", StartTimeString);
	fprintf(LogWriter, "���ڱ��ر��� %s��\n", EndTimeString);
	fprintf(LogWriter, "������ʾ����ϢΪ��\n%s\n", Text);
	fprintf(LogWriter, "������ʾ�ı���Ϊ��%s\n", Title);
	fprintf(LogWriter, "\n------\n\n");
}
