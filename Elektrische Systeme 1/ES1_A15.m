%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 15
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

% Vorgabe der Widerstände und Spannungen:
R1=100;
R2=10;
R3=50;
R4=1000;
R5=10;
U01=100;
U02=200;
U03=300;

% Aufstellen der Widerstandsmatrix:
R=[  1  1  1 -1
     R1 0  0  R4
     0  R2 0  R4
     0  0  R3 R4]

% Aufstellen des Spannungsvektors:
U0=[ 0; U01; U02; U03]

% Lösung des Gleichungssystems:
I=inv(R)*U0

% Berechnung der Ersatzquelle und damit I5:
UERS=I(4)*R4
IK=U01/R1+U02/R2+U03/R3
RERS=UERS/IK
I5=UERS/(R5+RERS)

% Darstellung von UAB abhängig von R5:
r5=linspace(2000,00,100);
i5=UERS./(r5+RERS);
u5=i5.*r5;
plot(r5,u5)
title('Aufgabe 15')
xlabel('Widerstand R5')
ylabel('Spannung U5')
grid
