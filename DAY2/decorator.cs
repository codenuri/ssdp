
byte[] arr = new byte[1024 * 1024 * 100]; // 100M 데이타


FileStream fs = new FileStream("a.txt", FileMode.Create);


fs.Write(arr, 0, arr.Length);

fs.Close();