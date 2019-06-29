#S = [v; x]
function Si1 = forwardEuler(Si, Ti, Dt)
  Si1 = Si + (Dt * F(Si, Ti));
endfunction
