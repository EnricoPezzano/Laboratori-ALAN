%   n rappresenta la dimensione della matrice quadrata e del vetore
%   a è la matrice
%   y è il vettore autovalori
%   it_max è il numero massimo di iterazioni
%   tol è la tolleranza dell'errore
function [ y, lambda, it_num ] = potenze( n, a, y, it_max, tol )
  y = y ( : );
  lambda = 0.0;
  y = y / norm ( y );
  it_num = 0;
  y_old = y;
  ay = a * y;
  lambda = y' * ay;
  y = ay / norm ( ay );
  if ( lambda < 0.0 )
    y = - y;
  end
  val_dif = 0.0;
  cos_y1y2 = y' * y_old;
  sin_y1y2 = sqrt ( ( 1.0 - cos_y1y2 ) * ( 1.0 + cos_y1y2 ) );
  for it_num = 1 : it_max
    lambda_old = lambda;
    y_old = y;
    ay = a * y;
    lambda = y' * ay;
    y = ay / norm ( ay );
    if ( lambda < 0.0 )
      y = - y;
    end
    val_dif = abs ( lambda - lambda_old );
    sin_y1y2 = 0;
    cos_y1y2 = y' * y_old;
    sin_y1y2 = sqrt ( ( 1.0 - cos_y1y2 ) * ( 1.0 + cos_y1y2 ) );
    if ( val_dif <= tol )
      break
    end 
  end
  y = ay / lambda;
  return
end