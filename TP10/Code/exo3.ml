print_int(5);print_newline();;
print_float(5.);print_newline();;
print_string("Salut");print_newline();;

(* On reprend la fonction de la Q1 *)
let est_pair (a:int) : bool = 
  match a mod 2 with
  | 0 -> true
  | 1 -> false
  | _ -> failwith"N'est pas censé arrivé"

(* prend en entrée un entier et l'affiche ssi il est pair *)
let print_pair (n:int) : unit =
  if est_pair n then print_int n;
  print_newline ();;

(* Prend un tripler (int*int*int) et affiche uniquement ceux qui sont paires*)
let print_pairs (a,b,c : int*int*int) : unit =
  print_pair a;print_pair b;print_pair c;;

(* Prend en entrée un string s et affiche s suivi d'un retour à la ligne *)
let print_retour (s:string) : unit =
  print_string s; print_newline ();;