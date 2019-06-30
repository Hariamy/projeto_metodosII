#S = [v; x]
function inte = integral4ordem(Si, Ti, Dt, w, m)
  k1 = F(Si, Ti, w, m);
  k2 = F(Si + (k1 * (Dt / 2)), Ti + (Dt / 2), w, m);
  k3 = F(Si + (k2 * (Dt / 2)), Ti + (Dt / 2), w, m);
  k4 = F(Si + (k3 * Dt), Ti + Dt, w, m);
  
  inte = (k1 + (2 * k2) + (2 * k3) + k4) / 6;
endfunction
