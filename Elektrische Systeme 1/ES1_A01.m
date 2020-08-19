%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 1
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

A = 1.5;      % Fläche in mm^2
n = 8.4e28;   % Leitungselektronendichte in m^-3
S = 6;		  % Stromdichte in A/mm^2
e = 1.6e-19   % Elektronenladung in As

% Berechnung der Elektronengeschwindigkeit
% Ansatz: I = n*e*v*A
v = S/n/e * 1e9

% pro Sekunde transportierte Anzahl von Elektronen:
N = S*A/e

