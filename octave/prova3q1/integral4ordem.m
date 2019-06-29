#S = [v; x]
function inte = integral4ordem(Si, Ti, Dt)
  k1 = F(Si, Ti);
  k2 = F(Si + (k1 * (Dt / 2)), Ti + (Dt / 2));
  k3 = F(Si + (k2 * (Dt / 2)), Ti + (Dt / 2));
  k4 = F(Si = (k3 * Dt), Ti + Dt);
  
  inte = (k1 + (2 * k2) + (2 * k3) + k4) / 6;
endfunction
