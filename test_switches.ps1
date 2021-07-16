$port= new-Object System.IO.Ports.SerialPort COM6,9600,None,8,one
$port.open()
$port.WriteLine("switch1_on")
Start-Sleep -s 1
$port.WriteLine("switch2_on")
Start-Sleep -s 1
$port.WriteLine("switch3_on")
Start-Sleep -s 1
$port.WriteLine("switch4_on")
Start-Sleep -s 2
$port.WriteLine("switch1_off")
Start-Sleep -s 1
$port.WriteLine("switch2_off")
Start-Sleep -s 1
$port.WriteLine("switch3_off")
Start-Sleep -s 1
$port.WriteLine("switch4_off")
$port.Close()
