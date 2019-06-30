#intervalo = [inicio, fim]
#S = [v; x]
function resul = prova3q1(S0, intervalo, Dt, erro, w, m)
  Sant = zeros(2, 1);
  Snovo = S0;
  ant = 0;
  novo = 1;
  vezes = 0;
  
  while (abs((novo - ant) / novo) >= erro)
    ant = novo;
    Sant = Snovo;
    
    Snovo = S0;
    for Ti = intervalo(1,1) : Dt : intervalo(1,2)
      Snovo = runge_kutta(Snovo, Ti, Dt, w, m);
    endfor
    
    novo = Snovo(2, 1);
    Dt /= 2;
  endwhile
  
  resul = Snovo;
endfunction
