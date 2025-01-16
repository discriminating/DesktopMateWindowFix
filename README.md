# DesktopMateWindowFix
Removes the DesktopMate window from Alt/Tab, Win/Tab, and the taskbar.  
Works with RetroBar, Start11, MyDockFinder, etc.

## Installation

### Automatic Startup
1. Download the [DesktopMateWindowFix executable](https://github.com/discriminating/DesktopMateWindowFix/releases/download/ajwesifdcjed/DesktopMateWindowFix.exe).
2. Copy the file to the Windows Startup folder:  
   `C:\Users\%USERNAME%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup`
3. The fix will automatically apply every time you log in.

### Manual (No Startup)
1. Open DesktopMate.
2. Run the executable manually.

## How It Works
DesktopMateWindowFix:
1. Strips the **WS_EX_APPWINDOW** extended window style, preventing the window from appearing in Alt/Tab or Win/Tab menus.
2. Applies the **WS_EX_TOOLWINDOW** style to hide it from the taskbar.
3. Parents the DesktopMate window to a dummy `STATIC` window, which is another hack to remove from the taskbar.
