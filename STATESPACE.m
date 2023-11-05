
g = 9.81;
rZero = 0;
qZero = 0;
wZero = 0;
vZero = 0;
uZero = 0;
rollZero = 0; %% phi
pitchZero = 0; %% theta
yawZero = 0; %% psi

dynamicPressure = 1;
fuselageDiameter = 1;
fuselageCrossSecA = 1;
aeroAxial = 1;
aeroLateral = 1;
aeroNormal = 1;
m = 1;
vNorm = 1;
COP = 1;
COM = 1;
statStabilityMargin = (COP - COM) / fuselageDiameter;
inertiaTransverse = 1;

a11 = 0;
a12 = rZero;
a13 = -qZero;
a14 = -wZero;
a15 = vZero;
a16 = g * sin(pitchZero) * cos(yawZero);
a17 = g * cos(pitchZero) * sin(yawZero);
a21 = -rZero;
a22 = (dynamicPressure * fuselageCrossSecA * aeroLateral) / (m * (1 - (vZero^2)/(vNorm^2)^0.5));
a23 = 0;
a24 = 0;
a25 = -uZero;
a26 = -g * (sin(rollZero)*cos(pitchZero)*cos(yawZero) - cos(rollZero)*sin(yawZero));
a27 = g * (sin(rollZero)*cos(pitchZero)*cos(yawZero) + cos(rollZero)*sin(yawZero));
a31 = qZero + ((dynamicPressure * fuselageCrossSecA * aeroNormal * wZero) / (m * (uZero^2 + wZero^2)));
a32 = 0;
a33 = - ((dynamicPressure * fuselageCrossSecA * aeroNormal * wZero) / (m * (uZero^2 + wZero^2)));
a34 = uZero;
a35 = 0;
a36 = -g * cos(rollZero) * cos(pitchZero) * cos(yawZero);
a37 = -g * (-cos(rollZero) * sin(pitchZero) * sin(yawZero) + sin(rollZero) * cos(yawZero));
a41 = (dynamicPressure * fuselageDiameter * fuselageCrossSecA * statStabilityMargin * aeroNormal * wZero) / (inertiaTransverse * (uZero^2 + wZero^2));
a42 = 0;
a43 = -(dynamicPressure * fuselageDiameter * fuselageCrossSecA * statStabilityMargin * aeroNormal * uZero) / (inertiaTransverse * (uZero^2 + wZero^2));
a44 = (dynamicPressure * fuselageCrossSecA * fuselageDiameter^2 * (1)) / (2 * inertiaTransverse * vNorm);
a45 = 0;
a46 = 0;
a47 = 0;
a51 = 0;
a52 = (dynamicPressure * fuselageDiameter * fuselageCrossSecA * statStabilityMargin * aeroLateral) / (inertiaTransverse * vNorm * (1 - (vZero^2) / (vNorm^2)));
a53 = 0;
a54 = 0;
a55 = (dynamicPressure * fuselageCrossSecA * fuselageDiameter^2 * (1)) / (2 * inertiaTransverse * vNorm);
a56 = 0;
a57 = 0;
a61 = 0;
a62 = 0;
a63 = 0;
a64 = cos(rollZero);
a65 = -sin(rollZero);
a66 = 0;
a67 = 0;
a71 = 0;
a72 = 0;
a73 = 0;
a74 = 0;
a75 = cos(rollZero) / cos(pitchZero);
a76 = ((qZero * sin(rollZero)) + (rZero * sin(pitchZero))) * sin(pitchZero) / (cos(pitchZero)^2);
a77 = 0;

A = [
    a11 a12 a13 a14 a15 a16 a17;
    a21 a22 a23 a24 a25 a26 a27;
    a31 a32 a33 a34 a35 a36 a37;
    a41 a42 a43 a44 a45 a46 a47;
    a51 a52 a53 a54 a55 a56 a57;
    a61 a62 a63 a64 a65 a66 a67;
    a71 a72 a73 a74 a75 76 a77;
    ]

