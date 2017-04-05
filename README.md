# regdelete
A small program to delete a registry key every five seconds.

# Usage
regdelete <root> <path>
Example: regdelete HKLM SOFTWARE\Policies\Google
Will delete SOFTWARE\Policies\Google under HKEY_LOCAL_MACHINE every five seconds.

Best used with windows task manager. that way one can start the program elevated on windows startup
