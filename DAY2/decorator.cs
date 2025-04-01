
using System.IO.Compression;

byte[] arr = new byte[1024 * 1024 * 100]; // 100M 데이타


FileStream fs = new FileStream("a.dat", FileMode.Create);

//fs.Write(arr, 0, arr.Length);

// 아래 코드가 Decorator 패턴을 사용해서 압축해서 파일에 쓰는 코드 입니다.
GZipStream zs = new GZipStream(fs, CompressionMode.Compress);
zs.Write(arr, 0, arr.Length);

fs.Close();

// 프로젝트이름/bin/debug/net8.0/a.dat 있습니다.