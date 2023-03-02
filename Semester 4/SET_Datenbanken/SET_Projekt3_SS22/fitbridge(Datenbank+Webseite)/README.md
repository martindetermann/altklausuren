Um diese Webseite auf Ihrem Komputer einzurichten brauchen Sie XAMPP. 

Dieses Vid zeigt wie man es auf Windows11 einrichtet: (https://www.youtube.com/watch?v=081xcYZKOZA)

Um die Webseite auf Ihrem Komputer einzurichten, mussen Sie in das htdocs Verzeichnis wechseln. 

Gebe dazu, je nachdem wo Sie XAMPP installiert haben, in der MSYS2 Konsole (oder andere Linux Konsole) den Befehl:

cd <xampp install location>/xampp/htdocs
 
 ein. Dann können Sie das Repository in der MSYS Konsole mit dem Befehl:

git clone https://ifst.ostfalia.de/gitlab/mdetermann/fitbridge.git

in dem htdocs Verzeichnis clonen. 

Wichtig: der Folder namens fitbridge sollte zu fitness24_frontend umbenannt werden.

 Sofern das funktioniert hat, können Sie Ihr XAMPP Server starten.

Geben Sie dann in den Browser http://localhost/phpmyadmin ein. 

Erstellen Sie dort eine leere Datenbank mit dem Namen fitness_datenbank (oben links auf +Neu drucken, namen eingeben und dann auf OK)

Drücke auf die neu erstellte Datenbankm und drücke dann auf "import"

Drücke von der import Seite auf "choose file"

Wähle die Datei namens "fitness_datenbank.sql" aus dem htdocs/ Folder und drücke auf öffnen

Jetzt sollte alles eingerichtet sein. Um das zu testen, können Sie in Ihrem Browser die URL:

http://localhost/<NAME DES FOLDERS>/fitness24_frontend/index.html

eingeben.  

## Testfälle

*Bitte bearbeitet diese damit sie vollständig sind*
*zudem könnten noch einige subtests (z.B. falsches PW eingeben oder falscher username registrieren usw.) hinzugefügt werden*
Jetzt sollte die Webseite mit der komplett leeren Datenbank verknüpft sein. Der Tester simuliert jetzt die Rolle des Fitnessstudios „Fitness24“ der diese Webseite frisch bekommen hat, und jetzt einrichten will. 

1)	TESTFALL 0: Einrichten der Datenbank
2)	XAMPP vollständig einrichten: //www.youtube.com/watch?v=081xcYZKOZA
3)	Datei entpacken:
4)	Die „fitbridge.zip“Datei in dem „htdocs“ Folder mit dem Verzeichnis „<…>/xampp/htdocs“ entpacken
5)	Von der „localhost“ Startseite auf „phpMyAdmin“ drücken
6)	(Von „phpMyAdmin“ Seite) den „+ Neu“ Knopf in der Leiste auf der Linken Seite drücken, um eine neue, leere Datenbank zu erzeugen.
7)	Als Namen der Datenbank „fitness_datenbank“ eingeben.
8)	Auf Erstellen drücken sodass eine neue, leere Datenbank eingerichtet wird.
9)	Von der neuen Datenbank auf „import“ drücken
10)	Auf „Datei Auswählen“ drücken
11)	Die „fitness_datenbank.sql“ Datei aus dem Verzeichnis „<…>/xampp/htdocs/fitbridge/fitness_datenbank.sql“ auswählen.
12)	Nun sollten die Drei Tabellen „users“, „messages“ und „appointments“ einsehbar sein.
13)	Bevor die Frontend geladen werden kann, müssen zuerst die Zugriffsdaten zu Ihrem XAMPP Server festgelegt werden, sofern diese dem Standard abweichen, sonst ist dieser Schritt unnötig.
14)	Öffnen Sie dazu die Datei:
„<…>/xampp/htdocs/fitbridge/inc/php_sql_inc.php“
und geben Sie die von Ihnen festgelegten Werte überall ein wo „set …“ als Kommentar steht
15)	Geben Sie in einem beliebigen Browser „localhost/fitbridge“ ein.
16)	Sofern die Index Seite sichtbar ist, sollten Sie mit den Testfällen beginnen können.
 
18)	TESTFALL 1: Neues Fitnessstudio (leere Datenbank) registriert den ersten Admin/Trainer
19)	Eingeben von:
„localhost/fitbridge/register_admin.php“
um zur Admin Registrierungsseite zu kommen
20)	Nun können die Felder ausgefüllt werden. Folgende Eingabefehler sollten von dem System verhindert werden:
-	Leeres Passwort, Leerer Vor- oder Nachname, Leerer Benutzername
-	Bereits existierender Benutzername
-	Geburtsdatum in Zukunft
Eine entsprechende Fehlermeldung sollte auch direkt in der Registrierungsseite angezeigt werden.
21)	Eingeben von:
„localhost/fitbridge/register_trainer.php“
um zur Trainer Registrierungsseite zu kommen.
22)	Nun können die Felder ausgefüllt werden. Folgende Eingabefehler sollten von dem System verhindert werden:
-	Leeres Passwort, Leerer Vor- oder Nachname, Leerer Benutzername
-	Bereits existierender Benutzername
-	Geburtsdatum in Zukunft
Eine entsprechende Fehlermeldung sollte auch direkt in der Registrierungsseite angezeigt werden.
23)	TESTFALL 2: Datenbank ist ‚eingerichtet‘ (mind. 1 Trainer/Admin in DB vorhanden), Kunden können sich registrieren
24)	Webseite kann nun vom fiktiven FitBridge Kunde veröffentlicht werden. Somit können sich die ersten Kunden des Fitnessstudios anmelden.
25)	Kunden geben:
„localhost/fitbridge/index.html“
im Browser ein, um zur Homepage zu kommen.
26)	Auf „Registrieren“ drücken, um zur Kunden-Registrierungsseite zu gelangen
27)	Nun können die Felder ausgefüllt werden. Folgende Eingabefehler sollten von dem System verhindert werden:
-	Leeres Passwort, Leerer Vor- oder Nachname, Leerer Benutzername
-	Bereits existierender Benutzername
-	Geburtsdatum in Zukunft
-	IBAN zu kurz (mind. 22 Ziffern)
Eine entsprechende Fehlermeldung sollte auch direkt in der Registrierungsseite angezeigt werden.
 
29)	TESTFALL 3: Neukunde logged sich das erste Mal ein
30)	Von der Registrierungsseite (oder von index Seite) zur login.html Seite gelangen.
31)	Die entsprechenden Felder ausfüllen. Folgende Eingabefehler sollten von dem System verhindert werden:
-	Nicht existierender/Falscher Benutzername/Leere Eingabe (wird gleichbehandelt)
-	Falsches Passwort/Leeres Passwort (auch gleichbehandelt)
Diese Fehlermeldungen werden, im Gegensatz zu den anderen, auf einer anderen Seite angezeigt, und der Benutzer muss sich zurück-klicken.
32)	Bei richtiger Eingabe sollte der Kunde eingeloggt werden, und an die „user_page.php“ Seite weitergeleitet werden. Von da aus können Termine gebucht werden.
33)	TESTFALL 4: (Testfälle 0,1,2,3 sind Voraussetzung) Kunde Bucht Termin
34)	Um ein Termin zu buchen können Kunden auf dem „Termin Buchen“ Knopf drücken
35)	Damit werden sie zur „appointment.php“ Seite weitergeleitet. Von da aus können die Felder entsprechend ausgefüllt werden. Folgende Eingabefehler sollten von dem System verhindert werden:
-	Kein Trainer ausgewählt (falscher Trainer nicht möglich)
-	Datum in der Vergangenheit
-	Bereits existierenden Termin bei eingegebenem Trainer 
Diese Fehlermeldungen sollten direkt auf der Seite angezeigt werden.
36)	Nach der erfolgreichen Terminbuchung sollte der Benutzer zurück zur „user_page.php“ Seite zurückgeleitet werden. Dort sollten die Termine auch gleich angezeigt werden.
37)	TESTFALL 5: (Testfälle 0,1,2,3 sind Voraussetzung) Kunde schickt Nachricht an Trainer
38)	Dazu kann der Kunde direkt von der „user_page.php“ (nach erfolgreichem Einloggen) auf dem „Nachricht Senden“ Knopf drücken.
39)	Der Kunde sollte zur „message.php“ Seite weitergeleitet werden.
40)	Von da aus kann der Kunde das Formular entsprechend ausfüllen. Das System sollte gegen folgende falsche Eingaben schützen:
-	Kein Empfänger gewählt (falscher Empfänger nicht möglich)
-	Textfeld leer
-	Eine entsprechende Fehlermeldung wird direkt auf der Seite angezeigt.
Bei erfolgreicher Eingabe wird der Benutzer zurück zur „user_page.php“ geleitet.
41)	Nun sollte die Nachricht einsehbar sowie löschbar sein (bitte noch nicht löschen da es für die nächsten Tests noch benötigt wird).
42)	Kunde ausloggen
43)	TESTFALL 6: (Testfälle 0,1,2,3 sind Voraussetzung) Trainer loggt (zum ersten Mal) ein 
44)	Von der „index.html“ Seite auf dem „Einloggen“ Knopf drücken
45)	In der „login.html“ Seite die Daten des in TESTFALL 2 erstellten Trainers eingeben, um einzuloggen.
46)	Nach erfolgreichem einloggen sollten Trainer automatisch zur „trainer_page.php“ Seite weitergeleitet werden. Von da aus können Trainer Termine einsehen und Nachrichten Schicken.
47)	Der in TESTFALL 3 gebuchte Termin (oder Termine) sollten nun einsehbar sein.
48)	Die in TESTFALL  gesendete Nachricht sollte auch einsehbar sein.

49)	TESTFALL 7: (Testfälle 0,1,2,3 sind Voraussetzung) Trainer schickt Kunde eine Nachricht
50)	Als eingeloggter Trainer auf „Nachricht Senden“ drücken
51)	Von der entsprechenden Seite aus an dem in TESTFALL 2 erstellten Kunde eine Nachricht schicken.
52)	Trainer sollte wieder zurück zur „trainer_page.php“ Seite zurückgeleitet werden von wo aus dieser Nachricht, sowie die in vorherigen Tesfall vom Kunde geschickte Nachricht einsehbar sein sollten.
53)	TESTFALL 8: (Testfälle 0,1,2,3,6/7 sind Voraussetzung) Trainer löscht alle Nachrichten
54)	Nun soll kann der Trainer beide Nachrichten (nach Augenschein auf gleicher Art und Weise) löschen in dem er auf dem entsprechenden Knopf unter Nachrichten löschen drückt (ganz unten Auf der Seite, ist nicht direkt sichtbar). 
55)	Als Trainer ausloggen
56)	TESTFALL 9: (Testfälle 0..8 sind Voraussetzung) Kunde sieht die vorherigen Nachrichten
57)	Der eingeloggte Kunde kann nun von der „user_page.php“ aus die von ihm gesendete Nachricht sehen, kann diese auch löschen. 
58)	Kunde ausloggen
59)	TESTFALL 10: (Testfälle 0..8 sind Voraussetzung) Admin loggt sich erstmalig ein 
60)	Von der index.html Seite aus auf „einloggen“ drücken
61)	Die Daten von dem in TESTFALL 1 registrierten Admin in das „login.html“ Formular eingeben um als Admin eingeloggt zu werden.
62)	Nun sollte Admin direkt zur „admin_page.php“ Seite geleitet werden.
63)	Von der „admin_page.php“ Seite können auch unter Verwendung derselben Nachrichten Funktion Nachrichten geschickt sowie gelöscht werden, alle Termine können eingesehen werden und alle Trainer sowie Kunden sollten einsehbar und löschbar sein.

64)	TESTFALL 11: (Testfälle 0..10 sind Voraussetzung)  Admin löscht alle Kunden und Trainer
65)	Von der „admin_page.php“ Seite können nun die in den Vorherigen Anwendungsfällen erstellten Kunden/Trainer gelöscht werden. Idealerweise sollten auch die dazugehörigen Termine mit gelöscht werden, das ist aber noch nicht vollständig implementiert.
66)	Admin loggt sich aus.
67)	TESTFALL 12: nicht-eingeloggter/unberechtigter Nutzer versucht auf einer Webseite zuzugreifen
68)	In einem frischen Browser-Fenster (oder ausgeloggten Zustand) die URL:
„localhost/fitbridge/admin_page.php“
oder eine beliebige andere Seite, auf der kein Zugriff gewährt ist, eingeben. Es soll nun eine Fehlermeldung erscheinen und weiteres Vorgehen verhindert werden.
