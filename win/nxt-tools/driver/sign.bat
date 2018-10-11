rem Signs installers with CyberTech certicate on Windows 8.1 x86. %1 -- path to CyberTech certificate

"C:\Program Files\Windows Kits\8.1\bin\x86\Inf2Cat.exe" /driver:. /os:2000,XP_X86,XP_X64,Server2003_X86,Server2003_X64,Vista_X86,Vista_X64,Server2008_X86,Server2008_X64,7_X86,7_X64,Server2008R2_X64,Server8_X64,8_X86,8_X64,Server6_3_X64,6_3_X86,6_3_X64
"C:\Program Files\Windows Kits\8.1\bin\x86\SignTool.exe" sign /v /f "%1\CyberTechLabsSPC.pfx" lego_firmware_winusb_install.cat
"C:\Program Files\Windows Kits\8.1\bin\x86\SignTool.exe" sign /v /f "%1\CyberTechLabsSPC.pfx" lego_winusb_install.cat