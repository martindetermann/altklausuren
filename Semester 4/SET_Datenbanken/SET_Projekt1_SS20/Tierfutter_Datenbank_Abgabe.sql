-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 08. Jun 2020 um 11:25
-- Server-Version: 10.4.11-MariaDB
-- PHP-Version: 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `tierfutter`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `fuetterung`
--

CREATE TABLE `fuetterung` (
  `Fuetterungs_ID` int(11) NOT NULL,
  `Tier_ID` int(11) NOT NULL,
  `Sorte` varchar(50) NOT NULL,
  `Futtermenge (kg)` int(11) NOT NULL,
  `Fuetterungszeit` time NOT NULL,
  `Fuetterungstag` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `fuetterung`
--

INSERT INTO `fuetterung` (`Fuetterungs_ID`, `Tier_ID`, `Sorte`, `Futtermenge (kg)`, `Fuetterungszeit`, `Fuetterungstag`) VALUES
(1, 1, 'Eukalyptus', 1, '13:00:00', 'Montag'),
(2, 2, 'Banane', 3, '16:00:00', 'Donnerstag'),
(3, 3, 'Banane', 2, '15:00:00', 'Donnerstag'),
(4, 4, 'Heu', 3, '13:17:05', 'Dienstag'),
(5, 5, 'Heu', 2, '14:22:05', 'Donnerstag'),
(6, 6, 'Heu', 4, '15:25:08', 'Mittwoch'),
(7, 7, 'Heu', 3, '08:25:08', 'Freitag'),
(8, 8, 'Heu', 2, '11:26:48', 'Sonntag'),
(9, 9, 'Heu', 4, '18:26:48', 'Samstag'),
(10, 10, 'Heu', 1, '17:27:34', 'Montag'),
(11, 11, 'Banane', 3, '08:27:34', 'Dienstag'),
(12, 12, 'Banane', 3, '09:28:29', 'Donnerstag'),
(13, 13, 'Banane', 1, '14:28:29', 'Donnerstag'),
(14, 14, 'Banane', 1, '10:29:22', 'Samstag'),
(15, 15, 'Banane', 4, '09:29:22', 'Sonntag'),
(16, 16, 'Banane', 4, '13:30:43', 'Sonntag'),
(17, 17, 'Banane', 1, '17:30:43', 'Montag'),
(18, 18, 'Apfel', 5, '15:31:20', 'Dienstag'),
(19, 19, 'Apfel', 4, '09:31:20', 'Donnerstag'),
(20, 20, 'Apfel', 6, '12:32:56', 'Freitag'),
(21, 21, 'Apfel', 6, '13:32:56', 'Mittwoch'),
(22, 22, 'Apfel', 3, '18:26:34', 'Dienstag'),
(23, 23, 'Apfel', 4, '06:25:34', 'Sonntag'),
(24, 24, 'Apfel', 3, '09:34:22', 'Mittwoch'),
(25, 25, 'Apfel', 5, '14:15:22', 'Freitag'),
(26, 26, 'Apfel', 6, '12:20:48', 'Mittwoch'),
(27, 27, 'Apfel', 4, '12:08:48', 'Sonntag'),
(28, 28, 'Apfel', 3, '09:11:31', 'Dienstag'),
(29, 29, 'Apfel', 5, '16:00:31', 'Sonntag'),
(30, 30, 'Antilopenfleisch', 3, '16:38:30', 'Freitag'),
(31, 31, 'Antilopenfleisch', 5, '19:38:30', 'Donnerstag'),
(32, 32, 'Antilopenfleisch', 7, '17:20:25', 'Mittwoch'),
(33, 33, 'Antilopenfleisch', 8, '14:07:25', 'Samstag'),
(34, 34, 'Antilopenfleisch', 3, '17:40:19', 'Dienstag'),
(35, 35, 'Antilopenfleisch', 5, '10:55:19', 'Freitag'),
(36, 36, 'Antilopenfleisch', 4, '18:54:24', 'Dienstag'),
(37, 37, 'Eukalyptus', 3, '22:59:24', 'Freitag'),
(38, 38, 'Eukalyptus', 2, '09:42:04', 'Sonntag'),
(39, 39, 'Eukalyptus', 2, '15:42:04', 'Samstag'),
(40, 40, 'Eukalyptus', 4, '12:42:46', 'Montag'),
(41, 41, 'Eukalyptus', 3, '23:42:46', 'Dienstag'),
(42, 42, 'Eukalyptus', 3, '17:43:51', 'Donnerstag'),
(43, 43, 'Eukalyptus', 2, '18:43:51', 'Freitag'),
(44, 44, 'Eukalyptus', 1, '12:44:46', 'Freitag'),
(45, 45, 'Antilopenfleisch', 6, '23:44:46', 'Sonntag'),
(46, 46, 'Antilopenfleisch', 4, '13:45:47', 'Montag'),
(47, 47, 'Antilopenfleisch', 5, '16:05:47', 'Donnerstag'),
(48, 48, 'Antilopenfleisch', 3, '09:46:29', 'Donnerstag'),
(49, 49, 'Antilopenfleisch', 7, '13:00:29', 'Freitag'),
(50, 50, 'Banane', 3, '14:20:14', 'Samstag'),
(51, 51, 'Banane', 5, '17:15:14', 'Donnerstag'),
(52, 52, 'Banane', 5, '19:00:04', 'Dienstag');

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `lager`
--

CREATE TABLE `lager` (
  `Sorte` varchar(50) NOT NULL,
  `Beschreibung` varchar(20) NOT NULL,
  `Anzahl Einheiten` int(11) NOT NULL,
  `Menge/Einheit` int(11) NOT NULL,
  `Min. Einheit` int(11) NOT NULL,
  `Max Einheit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `lager`
--

INSERT INTO `lager` (`Sorte`, `Beschreibung`, `Anzahl Einheiten`, `Menge/Einheit`, `Min. Einheit`, `Max Einheit`) VALUES
('Antilopenfleisch', 'Keule', 3, 15, 2, 7),
('Apfel', 'kg', 10, 1, 10, 50),
('Banane', 'kg', 5, 1, 4, 8),
('Eukalyptus', 'kg', 4, 1, 3, 7),
('Heu', 'Ballen', 1, 50, 2, 5);

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `tier`
--

CREATE TABLE `tier` (
  `Tier_ID` int(11) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `Geburtsdatum` date NOT NULL,
  `Tierart` varchar(50) NOT NULL,
  `Geschlecht` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Daten für Tabelle `tier`
--

INSERT INTO `tier` (`Tier_ID`, `Name`, `Geburtsdatum`, `Tierart`, `Geschlecht`) VALUES
(1, 'Antonio', '2019-05-08', 'Koala', 'männlich'),
(2, 'Lukas', '2020-05-19', 'Affe', 'männlich'),
(3, 'Marie', '2020-03-17', 'Affe', 'weiblich'),
(4, 'Ralf', '1990-04-23', 'Lama', 'männlich'),
(5, 'Jana', '1980-06-19', 'Lama', 'weiblich'),
(6, 'Hubertus', '1986-04-19', 'Lama', 'männlich'),
(7, 'Gertrud', '1992-05-09', 'Lama', 'weiblich'),
(8, 'Simone', '1993-01-27', 'Lama', 'weiblich'),
(9, 'Kord', '1993-10-13', 'Lama', 'männlich'),
(10, 'Corinna', '1994-03-09', 'Lama', 'weiblich'),
(11, 'Babette', '1994-10-08', 'Affe', 'weiblich'),
(12, 'Sandra', '1995-08-03', 'Affe', 'weiblich'),
(13, 'Horst', '2000-01-08', 'Affe', 'männlich'),
(14, 'Alwin', '2001-06-05', 'Affe', 'männlich'),
(15, 'Caroline', '2003-06-30', 'Affe', 'weiblich'),
(16, 'Bernd', '2003-08-09', 'Affe', 'männlich'),
(17, 'Beate', '2006-11-11', 'Affe', 'weiblich'),
(18, 'Theresa', '2008-01-14', 'Elefant', 'weiblich'),
(19, 'Wieland', '2009-12-06', 'Elefant', 'männlich'),
(20, 'Torsten', '2010-03-15', 'Elefant', 'männlich'),
(21, 'Ottokar', '2010-08-02', 'Elefant', 'männlich'),
(22, 'Gabi', '2011-03-18', 'Elefant', 'weiblich'),
(23, 'Gunda', '2012-11-21', 'Elefant', 'weiblich'),
(24, 'Raffael', '2013-10-18', 'Elefant', 'männlich'),
(25, 'Hannes', '2015-05-20', 'Elefant', 'männlich'),
(26, 'Annelise', '2017-01-12', 'Elefant', 'weiblich'),
(27, 'Hilbert', '2017-03-04', 'Elefant', 'männlich'),
(28, 'Manuela', '2017-03-21', 'Elefant', 'weiblich'),
(29, 'Carina', '2020-02-03', 'Tiger', 'weiblich'),
(30, 'Armin', '1980-10-31', 'Tiger', 'männlich'),
(31, 'Reinhardt', '1981-08-30', 'Tiger', 'männlich'),
(32, 'Edmund', '1983-03-31', 'Tiger', 'männlich'),
(33, 'Ansgar', '1983-06-02', 'Tiger', 'männlich'),
(34, 'Cornelia', '1985-02-26', 'Tiger', 'weiblich'),
(35, 'Cathrin', '1987-10-15', 'Tiger', 'weiblich'),
(36, 'Jana', '1993-06-10', 'Tiger', 'weiblich'),
(37, 'Theo', '1993-08-25', 'Koala', 'männlich'),
(38, 'Willy', '1995-12-03', 'Koala', 'männlich'),
(39, 'Birgit', '1997-11-26', 'Koala', 'weiblich'),
(40, 'Heida', '1998-12-28', 'Koala', 'weiblich'),
(41, 'Lucia', '2002-02-28', 'Koala', 'weiblich'),
(42, 'Emanuel', '2004-04-05', 'Koala', 'männlich'),
(43, 'Petrus', '2004-07-09', 'Koala', 'männlich'),
(44, 'Theodor', '2006-05-24', 'Koala', 'männlich'),
(45, 'Ingrid', '2006-07-10', 'Tiger', 'weiblich'),
(46, 'Martin', '2008-07-08', 'Tiger', 'männlich'),
(47, 'Frank', '2009-03-06', 'Tiger', 'männlich'),
(48, 'Ada', '2012-06-15', 'Tiger', 'weiblich'),
(49, 'Arno', '2015-04-14', 'Tiger', 'männlich'),
(50, 'Cord', '2015-08-28', 'Affe', 'männlich'),
(51, 'Alex', '2015-08-31', 'Affe', 'männlich'),
(52, 'Augustin', '2016-08-11', 'Affe', 'männlich');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `fuetterung`
--
ALTER TABLE `fuetterung`
  ADD PRIMARY KEY (`Fuetterungs_ID`);

--
-- Indizes für die Tabelle `lager`
--
ALTER TABLE `lager`
  ADD PRIMARY KEY (`Sorte`);

--
-- Indizes für die Tabelle `tier`
--
ALTER TABLE `tier`
  ADD PRIMARY KEY (`Tier_ID`);

--
-- AUTO_INCREMENT für exportierte Tabellen
--

--
-- AUTO_INCREMENT für Tabelle `fuetterung`
--
ALTER TABLE `fuetterung`
  MODIFY `Fuetterungs_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=53;

--
-- AUTO_INCREMENT für Tabelle `tier`
--
ALTER TABLE `tier`
  MODIFY `Tier_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=53;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
