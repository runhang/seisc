#include "stdafx.h"
#include "dirread.h"


DirRead::DirRead()
{
}


DirRead::~DirRead()
{
}


//��ȡ���е��ļ���  
// �ú�����������������һ��Ϊ·���ַ���(string���ͣ����Ϊ����·��)��  
// �ڶ�������Ϊ�ļ������ļ����ƴ洢����(vector����,���ô���)��  
// ���������е��ø�ʽ(��������������ļ�"AllFiles.txt"�У���һ��Ϊ����)��
void DirRead::GetAllFiles(string path, vector<string>& files)
{

	long   hFile = 0;
	//�ļ���Ϣ    
	struct _finddata_t fileinfo;
	string dir;
	if ((hFile = _findfirst(dir.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					files.push_back(dir.assign(path).append("\\").append(fileinfo.name));
					GetAllFiles(dir.assign(path).append("\\").append(fileinfo.name), files);
				}
			}
			else
			{
				files.push_back(dir.assign(path).append("\\").append(fileinfo.name));
			}

		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}

}

//��ȡ�ض���ʽ���ļ���  
// �ú�����������������һ��Ϊ·���ַ���(string���ͣ����Ϊ����·��)��  
// �ڶ�������Ϊ�ļ������ļ����ƴ洢����(vector����,���ô���)��  
// ���������е��ø�ʽ(��������������ļ�"AllFiles.txt"�У���һ��Ϊ����)��
void DirRead::GetAllFormatFiles(string path, vector<string>& files, string format)
{
	//�ļ����    
	long   hFile = 0;
	//�ļ���Ϣ    
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
					GetAllFormatFiles(p.assign(path).append("\\").append(fileinfo.name), files, format);
				}
			}
			else
			{
				files.push_back(p.assign(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}

 