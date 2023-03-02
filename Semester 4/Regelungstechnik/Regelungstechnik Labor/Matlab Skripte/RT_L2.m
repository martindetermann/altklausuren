% Labor Reglungstechnik (SoSe2022)
% Aufgaben für Labor 2
%
% Bearbeitet von: 
% --, --, --
% --, --, --

clear, clc, close all;
s=tf('s');

% Parameter und Beiwerte:
T1=4;
T2=0.5;
T3=2;
Ks=5;
Kr=0.19;
Tn=4;
Tv=2;

% Regler:
%Gr=Kr; %P-Regler
Gr=Kr*(1+Tn*s)/(Tn*s); %PI-Regler
%Gr=Kr*(1+s*Tn)*(1+s*Tv)/s; %PID-Regler

% Übertragungsfunktion (PT3-Strecke):
G1=1+s*T1;
G2=1+s*T2;
G3=1+s*T3;
Gs=Ks/((G1)*(G2)*(G3));

% offener Regelkreis:
go=series(Gr,Gs);

% geschlossener Regelkreis:
g=feedback(go,1);

% Führungsübertragungsfunktion [X=W(Gs*Gr)-X(Gs*Gr)]:
Gw=go/(1+go);

% Störübertragungsfunktion: [X=Z(Ks/G3)-X(Gs*Gr)]:
Gz=((Ks)/(1+T3*s))/(1+go);

% Bode-Diagramm:
figure(1)
bode(go)

% Sprungantwort:
figure(2)
step(Gw)
title('Führungsübertragungsfunktion Gw(s)')

figure(3)
step(Gz)
title('Störübertragungsfunktion Gz(s)')
