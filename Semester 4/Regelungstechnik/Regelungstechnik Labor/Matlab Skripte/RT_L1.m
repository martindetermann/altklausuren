%% Labor Reglungstechnik (SoSe2022)
% Aufgaben für Labor 1
%
% Bearbeitet von: 
% --,    --,    --
% --,         --,      --

%% Aufgabe 1 (P-Regler):
% Parameter und Beiwerte:
V=5;
T1=10;

Kp1=2;
Kp2=10;
Kp3=20;
Kp4=50;

% PT1 Strecke:
s=tf('s');
G1=V/(1+T1*s);

% P-Regler:
Gr1=Kp1;
Gr2=Kp2;
Gr3=Kp3;
Gr4=Kp4;

% offener Regelkreis:
go1=series(Gr1,G1);
go2=series(Gr2,G1);
go3=series(Gr3,G1);
go4=series(Gr4,G1);

% geschlossener Regelkreis:
g1=feedback(go1,1);
g2=feedback(go2,1);
g3=feedback(go3,1);
g4=feedback(go4,1);

% Sprungantwort:
figure(1)
step(g1)
hold on
step(g2)
hold on
step(g3)
hold on
step(g4)

% Ortskurve:
figure(2)
nyquist(go1)
hold on
nyquist(go2)
hold on
nyquist(go3)
hold on
nyquist(go4)

% Bode-Diagramm:
figure(3)
bode(go1)
hold on 
bode(go2)
hold on
bode(go3)
hold on
bode(go4)

% Pol-Nullstellen-Diagramm:
figure(4)
pzmap(g1)
hold on 
pzmap(g2)
hold on
pzmap(g3)
hold on
pzmap(g4)

%% Aufgabe 2 (I-Regler):
% Parameter und Beiwerte:
V=2;
T1=10;

Ki1=1;
Ki2=5;
Ki3=10;
Ki4=100;

% PT1 Strecke:
s=tf('s');
G1=V/(1+T1*s);

% I-Regler:
Gr1=Ki1/s;
Gr2=Ki2/s;
Gr3=Ki3/s;
Gr4=Ki4/s;

% offener Regelkreis:
go1=series(Gr1,G1);
go2=series(Gr2,G1);
go3=series(Gr3,G1);
go4=series(Gr4,G1);

% geschlossener Regelkreis:
g1=feedback(go1,1);
g2=feedback(go2,1);
g3=feedback(go3,1);
g4=feedback(go4,1);

% Sprungantwort:
figure(1)
step(g1)
hold on
step(g2)
hold on
step(g3)
hold on
step(g4)

% Ortskurve:
figure(2)
nyquist(go1)
hold on
nyquist(go2)
hold on
nyquist(go3)
hold on
nyquist(go4)

% Bode-Diagramm:
figure(3)
bode(go1)
hold on 
bode(go2)
hold on
bode(go3)
hold on
bode(go4)

% Pol-Nullstellen-Diagramm:
figure(4)
pzmap(g1)
hold on 
pzmap(g2)
hold on
pzmap(g3)
hold on
pzmap(g4)

%% Aufgabe 3 (PI-Regler):
% Parameter und Beiwerte:
V=2;
T1=10;

Kp1=1;
Kp2=5;
Kp3=1;
Kp4=5;
Kp5=10;
Kp6=5;
KI1=1;
KI2=1;
KI3=5;
KI4=5;
KI5=1;
KI6=2;

% PT1 Strecke:
s = tf('s');
G1=V/(1+T1*s);

% PI-Regler:
Gr1=(Kp1*s+KI1)/s;
Gr2=(Kp2*s+KI2)/s;
Gr3=(Kp3*s+KI3)/s;
Gr4=(Kp4*s+KI4)/s;
Gr5=(Kp5*s+KI5)/s;
Gr6=(Kp6*s+KI6)/s;

% offener Regelkreis:
go1=series(Gr1,G1);
go2=series(Gr2,G1);
go3=series(Gr3,G1);
go4=series(Gr4,G1);
go5=series(Gr5,G1);
go6=series(Gr6,G1);

% geschlossener Regelkreis:
g1=feedback(go1,1);
g2=feedback(go2,1);
g3=feedback(go3,1);
g4=feedback(go4,1);
g5=feedback(go5,1);
g6=feedback(go6,1);

% Sprungantwort:
figure(1)
step(g1)
hold on
step(g2)
hold on
step(g3)
hold on
step(g4)
hold on
step(g5)
hold on
step(g6)
hold on

% Ortskurve:
figure(2)
nyquist(go1)
hold on
nyquist(go2)
hold on
nyquist(go3)
hold on
nyquist(go4)
hold on
nyquist(go5)
hold on
nyquist(go6)

% Bode-Diagramm:
figure(3)
bode(go1)
hold on 
bode(go2)
hold on
bode(go3)
hold on
bode(go4)
hold on
bode(go5)
hold on
bode(go6)
hold on

% Pol-Nullstellen-Diagramm:
figure(4)
pzmap(g1)
hold on 
pzmap(g2)
hold on
pzmap(g3)
hold on
pzmap(g4)
hold on
pzmap(g5)
hold on
pzmap(g6)