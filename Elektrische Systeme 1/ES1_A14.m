%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 14
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

% Vorgabe der Widerstände und Spannungen %
R1=100;
R2=10;
R3=50;
U01=100;
U02=200;

% Aufbau der Widerstandsmatrix
R=[   1     1
     R1+R3 -R2]

% Aufbau des Spannungsvektors:
U0=[ 0; U01-U02]

% Lösung des Gleichungssystems:
I=inv(R)*U0

% Ersatzspannung:
UERS=U02-I(2)*R2

% Kurzschlußstrom:
IK=U01/(R1+R3)+U02/R2

% Ersatzwiderstand:
RERS=UERS/IK

% Ergänzung: Strom und Spannung bei variablem Lastwiderstand
rv=linspace(0,10*RERS,100);
x=rv/RERS;
i=UERS./(rv+RERS);
u=i.*rv;
subplot(2,1,1)
plot(x,i)
title('Ergänzung Aufgabe 14')
xlabel('x')
ylabel('Strom Iv')
grid
subplot(2,1,2)
plot(x,u)
title('Aufgabe 14')
xlabel('x')
ylabel('Spannung Uv')
grid