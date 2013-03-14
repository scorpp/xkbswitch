#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

void PrintUsage();

int
main(int argc, char **argv)
{
    int xkbGroup;
    if (argc < 2 || (xkbGroup = atoi(argv[1])) < 0 || xkbGroup > 3)
    {
        PrintUsage();
        exit(0);
    }


	int xkbEventType, xkbError, xkbReason;
	int mjr = XkbMajorVersion, mnr = XkbMinorVersion;
	Display *display = NULL;

	display = XkbOpenDisplay(NULL, &xkbEventType, &xkbError, 
			&mjr, &mnr, &xkbReason);
	if (NULL == display)
	{
        warnx("Cannot open X display %s", XDisplayName(NULL));
        switch (xkbReason)
        {
            case XkbOD_BadServerVersion:
            case XkbOD_BadLibraryVersion:
                warnx("Incomatible versions of client and server xkb libraries");
                break;
            case XkbOD_ConnectionRefused:
                warnx("Connection to X server refused");
                break;
            case XkbOD_NonXkbServer:
                warnx("XKB extension is not present");
                break;
            default:
                warnx("Unknown error from XkbOpenDisplay: %d", xkbReason);
                break;
        }
        exit(1);
	}

    Bool status = XkbLockGroup(display, XkbUseCoreKbd, xkbGroup);

    XCloseDisplay(display);

    return status ? 0 : 1;
}

void 
PrintUsage()
{
    printf("Usage: xkbswitch [0-3] sets keyboard layout\n");
}
