
(* prend en entrée un triplet (a,b,c) et calcule le nombre de racines réelles
du polynôme aX^2 +bX +c *)
let n_roots (a,b,c : float*float*float) : int =
  let delta = b*.b -. 4.*.a*.c in
  if a=0. && b=0. then 0 else 
    if a=0. then 1 else 
      if  delta > 0. then 2 else
        if delta = 0. then 1 else 0

(* prend en entrée un entier n et si n est un chiffre entre 2 et 5 inclus 
renvoie si nom en toutes lettres sinon renvoie "" *)
let nom_chiffre (n:int) : string =
  match n with
  | 2 -> "deux"
  | 3 -> "trois"
  | 4 -> "quatre"
  | 5 -> "cinq"
  | _ -> ""

(* fonction qui prend en entrée x et y des entiers et renvoie différent cas explicité dans le match with *)
let g (x:int) (y:int) : int = 
  match (x-y,x+y) with
  | 0, _ | _,0 -> 0
  | 1, _ | -1,_ -> (x+y)*(x+y)+1
  | _, 1 | _, -1 -> (x-y)*(x-y)-1
  | _ -> x*y 

(* Prend un entier n et renvoie les cas déjà explicité dans le match with*)
let goubameu (n:int) : string = 
  match (n mod 3, n mod 5) with
  | 0,0 -> "meu"
  | 0,_ -> "gou"
  | _,0 -> "ba"
  | _,_ -> string_of_int n
