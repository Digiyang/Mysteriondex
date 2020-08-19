%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 7
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

G1 = 1/10;    % Leitwert in Siemens
G2 = 1/20;    % Leitwert in Siemens
G3 = 1/50;    % Leitwert in Siemens
I = 2;        % Strom in A

% Gesamtleitwert berechnen:
G_ges = G1 + G2 + G3;

% Spannung an Parallelschaltung berechnen
U = I/G_ges;

% Strom durch G1 = 1/R1:
I_G1 = U * G1

% Strom durch G2 = 1/R2:
I_G2 = U * G2

% Strom durch G3 = 1/R3:
I_G3 = U * G3
