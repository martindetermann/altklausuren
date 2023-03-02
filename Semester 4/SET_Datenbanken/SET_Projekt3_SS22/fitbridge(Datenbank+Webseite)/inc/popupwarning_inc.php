<?php
/**
 * FitBridge
 *
 * This php script displays a brief message notifying users about pop ups being blocked, in case redirects are prevented.
 * @return 0 in all cases, this script is too simple to have errors.
 * @author  Ahmed Sabti, Martin Determann, Bland Azad Saleem, Othmane Kribia
 * @license Only to be used by Fitness24 as permitted by contract [LINK TO CONTRACT]
 */

    echo "<body>Vermutlich liest du diese Nachricht weil dein Browser Pop-ups blockiert hat. <br>
          Damit das nicht nochmal passiert, solltest du deine Browsereinstellungen verändern, um pop-ups zu erlauben
          Lese hierzu mehr in dem untenliegenden Link: </body>";
    echo "<a href='https://support.purdue.edu/help/FootPrintsHelp/content/disable_popup_blockers.htm?CSHID=DisablePopupBlockers'>Link</a>";
    echo "<br>";
    return 0;