$port= new-Object System.IO.Ports.SerialPort COM6,9600,None,8,one
$port.open()
Start-Sleep -s 1
$port.WriteLine("STRING Hello World")
Start-Sleep -s 1
$port.WriteLine("ENTER")
Start-Sleep -s 1
$port.Close()
