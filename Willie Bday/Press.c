/* ---------------------------------------------------------------------------
 * PressAnyKey()
 * ---------------------------------------------------------------------------
 * Copyright 2008 Michael Thomas Greer
 * http://www.boost.org/LICENSE_1_0.txt
 *
 * function
 *   Optionally print a message and and wait for the user to press (and
 *   release) a single key.
 *
 * arguments
 *   The message to print. If NULL, uses a default message. Specify the empty
 *   string "" to not print anything.
 *
 * returns
 *   The virtual keycode for the key that was pressed.
 *
 *   Windows #defines virtual keycode values like
 *     VK_UP
 *     VK_DOWN
 *     VK_RIGHT
 *     VK_LEFT
 *   which you can use to identify special keys.
 *
 *   Letter keys are simply the upper-case ASCII value for that letter.
 */
#include <windows.h>

int PressAnyKey( const char *prompt )
  {
  DWORD        mode;
  HANDLE       hstdin;
  INPUT_RECORD inrec;
  DWORD        count;
  char         default_prompt[] = "Press a key to continue...";

  /* Set the console mode to no-echo, raw input, */
  /* and no window or mouse events.              */
  hstdin = GetStdHandle( STD_INPUT_HANDLE );
  if (hstdin == INVALID_HANDLE_VALUE
  || !GetConsoleMode( hstdin, &mode )
  || !SetConsoleMode( hstdin, 0 ))
    return 0;

  if (!prompt) prompt = default_prompt;

  /* Instruct the user */
  WriteConsole(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    prompt,
    lstrlen( prompt ),
    &count,
    NULL
    );

  FlushConsoleInputBuffer( hstdin );

  /* Get a single key RELEASE */
  do ReadConsoleInput( hstdin, &inrec, 1, &count );
  while ((inrec.EventType != KEY_EVENT) || inrec.Event.KeyEvent.bKeyDown);

  /* Restore the original console mode */
  SetConsoleMode( hstdin, mode );

  return inrec.Event.KeyEvent.wVirtualKeyCode;
  }