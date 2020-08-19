%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterl�sung - Aufgabe 5
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule f�r Technik Berlin
%--------------------------------------------------------------

clear
close all
home

rho_H2O = 999,97  % Dichte von Wasser in kg/m^3
V = 80;           % Volumen in m^3
g = 9.81;         % Erdbeschleunigung in m/s�
h = 8;            % H�hendifferenz in m
t = 3600;         % Zeitdauer in s
U = 200;          % Spannung in V

% gef�rderte Masse:
m = V*rho_H2O;

% Geleistete mechanische Arbeit:
W = m*g*h;

% Erforderliche Leistung der Pumpe:
P = W/t

% Wirkungsgrad = 80% --> elektrische Leistung = mechanische Leistung / 0.8
P_elekt = W/t/0.8

% aus P_elek = U*I folgt:
I = P_elekt/U