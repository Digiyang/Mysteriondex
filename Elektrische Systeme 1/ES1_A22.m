%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 22
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

f = 800;                   % Frequenz in Herz
om = 2*pi*f;               % Kreisfrequenz in 1/s
R = 10e3;                  % Widerstand in Ohm
phi = 20*pi/180;           % Winkel in rad
IR = 0.7e-3;               % Strom durch den Widerstand

U = IR*R                   % Spannung an der Parallelschaltung
C = tan(phi)/(om*R)        % Kapazität in Farad
Y = 1/R+j*om*C             % Leitwert der Parallelschaltung
Z = 1/Y                    % Scheinwiderstand
Z_Betrag = abs(Z)          % Betrag des Widerstandes
Z_Winkel = angle(Z)*180/pi % Phase des Widerstandes in deg
I = U/Z                    % komplexer Gesamtstrom in A
I_Betrag = abs(I)          % Betrag des Stromes
I_Winkel = angle(I)*180/pi % Phase des Stromes

compass([1/R j*om*C Y])    % Darstellung im Zeigerdiagramm