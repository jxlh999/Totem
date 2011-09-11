#include <iostream>
#include <stdlib.h>
#include "Object.h"

class File: public Object {
	pubic :File();
	File(char *path);
	File(char *parent_path, char *child);
	File(File& parent, char *child_path);
	//File(URI uri);
	char* GetName();
	char* GetParentPath();
	File& GetParentFile();
	char* GetPath();
	boolean IsAbsolute();
	char* GetAbsolutePath();
	File& GetAbsoluteFile();
	char* GetCanonicalPath();
	File& GetCanonicalFile();
	//URI& ToURI();
	boolean CanRead();
	boolean CanWrite();
	boolean Exists();
	boolean IsDirectory();
	boolean IsFile();
	boolean IsHidden();
	long LastModified();
	long CreatedDate();
	long Length();
	boolean CreateNewFile();
	boolean Delete();
	void DeleteOnExit();
	char* List();
	char* List(char* filter);
	//File[] ListFiles();
	//File[] ListFiles(char* filter);
	//File[] ListFiles(FileFilter filter);
	boolean Mkdir();
	boolean Mkdirs();
	boolean RenameTo(File& dest);
	boolean SetLastModified(long time);
	boolean SetReadOnly();
	boolean SetWriteable(boolean writeable, boolean owner_only);
	boolean SetWriteable(boolean writeable);
	boolean SetReadable(boolean readable, boolean owner_only);
	boolean SetReadable(boolean readable);
	boolean SetExecutable(boolean executable, boolean owner_only);
	boolean SetExecutable(boolean executable);
	boolean CanExecute();
	//static File[] ListRoots();
	long GetTotalSpace();
	long GetFreeSpace();
	long GetUsableSpace();
	static File& GenerateFile(char *prefix, char *suffix, File& dir);
	//static boolean CheckAndCreate(char *filename, SecurityManager mgr);
	static File& CreateTempFile(char *prefix, char *suffix, File& directory);
	static File& CreateTempFile(char *prefix, char *suffix);
	int CompareTo(File& path_name);
private:
	File(char *path, int prefix_len);
	File(char *child_path, File, parent);
	//void WriteObject(ObjectOutputStream s);
	//void ReadObject(ObjectInputStream s);

};
