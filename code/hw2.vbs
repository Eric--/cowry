On Error Resume Next

'url="http://bbs.3dmgame.com/thread-3458237-650-1.html"
url="http://bbs.3dmgame.com/thread-3296067-7169-1.html"
'url="http://bbs.3dmgame.com/thread-3475371-60-1.html"
dim message(6)
message(0)="֧��3DM ���϶���" 
message(1)=" ¥�������� ��{:3_154:}" 
message(2)="����Ʈ�����������������÷����ˣ�������" 
message(3)="{:3_152:}{:3_153:}{:3_154:}" 
message(4)=" ���϶��� ��¥����һ��" 
message(5)="��֧�ֶԲ����Լ���" 
message(6)="���������������ݣ���������" 

Sub AutoSendReply()
	do while(not ie.document is nothing)
		if ie.document.getelementbyid("fastpostmessage").value <> "" then
			ie.document.Location.Reload(True)
			wscript.sleep 18000
		end if
		randomize
		ie.document.getelementbyid("fastpostmessage").value=message(int((7*Rnd)))
		wscript.sleep 500  
		ie.document.getelementbyid("fastpostsubmit").click  
		wscript.sleep 18000
	loop
End Sub

do
	set ie=createobject("internetexplorer.application")  
	ie.navigate url  
	ie.Visible = false
	wscript.sleep 5000
	do while ie.ReadyState <> 4 or ie.busy  
		wscript.sleep 1000
	loop
	AutoSendReply
	ie.quit
loop

