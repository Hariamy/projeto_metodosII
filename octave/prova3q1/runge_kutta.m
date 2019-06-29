#S = [v; x]
function Si1 = runge_kutta(Si, Ti, Dt)
  Si1 = Si + (Dt * integral4ordem(Si, Ti, Dt));
endfunction
