%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 6
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

R1 = 10;    % Widerstand in Ohm
R2 = 20;    % Widerstand in Ohm
R3 = 50;    % Widerstand in Ohm
U = 20;     % Spannung in V

% Gesamtwiderstand berechnen
R_ges = R1 + R2 + R3;

% Strom durch die Reihenschaltung berechnen
I = U / R_ges;

% Spannung an R1:
U_R1 = I * R1

% Spannung an R2:
U_R2 = I * R2

% Spannung an R3:
U_R3 = I * R3
