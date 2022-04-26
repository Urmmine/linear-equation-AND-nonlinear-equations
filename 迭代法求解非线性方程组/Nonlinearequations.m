clear;
clc;
x=[0.8,0.6]';
f=F(x);
df=DF(x);
fprintf('%d %.7f %.7f\n',i,x(1),x(2));
N=4;
for i=1:N
    y=-inv(df)*f;
    x=x+y;
    f=F(x);
    df=DF(x);
    fprintf('%d %.7f %.7f\n',i,x(1),x(2));
    if norm(y)<0.0000001
        break;
    end
end