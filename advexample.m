A = 5.5 + 12 * sin(0.4) + 2.2^4;
B = [1.2 2.3 A;[1.3 2.4;4.6 1.3],[3.2;7.8]];
A
B
C = [[B [3.4; 2.1; 3.5+9.1]]
     1.2^3 3+1.2 15/(2.1+10*sin(0.12))  1.2]
D = rand(4,4)
E = eye(4, 4)
F = zeros(2, 3)
G = ones(3, 6)
L = (1.2 + 3.4 - 5.6)/(2.1*3.2 + 4.6) - 12.1*3.1 + (1.2 + 5.2)^(4/(3.2+5.6))

X = ((C*D .+ 4)./2.1 + sqrt(D))./C.^2
Y = (C^3 * sin(1./D))^(0.1)