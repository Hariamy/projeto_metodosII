#S = [v; x]
function Si1 = runge_kutta(Si, Ti, Dt, w, m)
  Si1 = Si + (Dt * integral4ordem(Si, Ti, Dt, w, m));
endfunction
