type boisson = 
| Eau
| Jus of string 
| Breizh_cola of bool (* true indique un breizh cola light, false, un normal*)
| Cocktail of boisson * boisson * float (* Float (entre 0 et 1) qui représentera la proportion de boisson dans le cocktail*)


(* Calcul le prix d'une boisson au litre*)
let rec prix (b:boisson) : float = 
  match b with
  |Eau -> 0.
  | Jus "ramboutan" | Jus "Ramboutan" -> 5.3
  | Jus _ -> 3.
  | Breizh_cola _ -> 1.
  | Cocktail (b1,b2,p) -> (prix b1)*.p +. (1.-.p)*.(prix b2)

(* Prend en entrée une liste de boisson et faisant un cocktail gigantesque du type
Cocktail(1/2, b1, cocktail(1/2,b2, cocktail(...cocktail(1/2,bn-1, bn)))) *)
let rec shaker (b:boisson list) :boisson = 
  match b with 
  | [] -> failwith "Liste vide !"
  | x::[] -> x
  | x::q -> Cocktail (x,shaker q, 0.5)

(* Calcul le nom d'une boisson de base (boisson de base = tout sauf cocktail) *)
let string_of_boisson (b:boisson) : string =
  match b with 
  | Eau -> "Eau"
  | Jus s -> if s.[0] = 'a' || s.[0] = 'A' || s.[0] = 'e' || s.[0] = 'E' || s.[0] = 'i' || s.[0] = 'I' || s.[0] = 'o' || s.[0] = 'O' || s.[0] = 'u' || s.[0] = 'U' || s.[0] = 'y' || s.[0] = 'Y'
    then "Jus d'"^s
  else "Jus de "^s
  | Breizh_cola b -> if b then "Breizh cola light" else "Breizh cola normal"
  | _ -> failwith"Pas de cocktail !"


(* Permet de transformer une boisson en une list de couples (b,x) ou
b est une boisson de base et x la proportion de cette boisson dans le 
cocktail *)
let rec ingredients_aux (b:boisson) (p:float) : (boisson*float) list =
  match b with 
  | Cocktail(b1,b2,p2) ->  (ingredients_aux b1 (p*.p2))@(ingredients_aux b2 (p-.p*.p2))
  | x -> [(x, p)]

let ingredients (b:boisson) : (boisson*float) list = ingredients_aux b 1.

(* Prend en entrée une liste de couples, regroupe les couples selon la première
composante et somme les deuxiemes composantes, on supp que la liste est triée *)
let rec agreg_sum_aux (l:('a*float) list) (acc:'a)  (res:float): ('a*float) list =
  (* acc stockera l'element actuel, res stockera la somme associé *)
  match (l,acc) with
  | [],_ -> [(acc,res)]
  | ((y, s)::q,x) -> if x=y then (agreg_sum_aux q x (res+.s) )
  else (x,res)::(agreg_sum_aux q y s)

let agreg_sum (l:('a*float) list) : ('a*float) list = 
  match l with
  | [] -> []
  | (x,y)::q -> agreg_sum_aux q x y

(* Prend une boisson (un Cocktail) et affiche la recette pour faire 1L de cette boisson *)
let rec recette_aux (b:(boisson*float) list) =
  match b with 
  | [] -> ()
  | (x,p)::q -> print_float (p*.1000.);print_string " mL "; print_string (string_of_boisson x);
  print_newline();recette_aux q;;

let recette (b:boisson) = 
  print_string"Recette pour 1L:\n";
  let boisson_liste = agreg_sum (ingredients b) in
  recette_aux boisson_liste;;


let test () = 
  assert(shaker [Eau;Eau;Eau;Eau] = Cocktail (Eau, Cocktail (Eau, Cocktail (Eau, Eau, 0.5), 0.5), 0.5));
  assert(shaker [Eau;Jus "Fraise";Breizh_cola true;Eau] = Cocktail (Eau,
  Cocktail (Jus "Fraise", Cocktail (Breizh_cola true, Eau, 0.5), 0.5), 0.5));
  assert(string_of_boisson (Jus "orange") = "Jus d'orange");
  assert(string_of_boisson (Breizh_cola true) = "Breizh cola light");
  assert(ingredients (Cocktail(Eau,Cocktail(Breizh_cola true, Cocktail(Jus "pomme",Jus "ananas",0.2),0.5),0.5))= 
  [(Eau, 0.5); (Breizh_cola true, 0.25); (Jus "pomme", 0.05);(Jus "ananas", 0.2)]);
  assert(agreg_sum [("bla",0.1);("bla",0.3);("truc",0.3);("truc",0.3)] = [("bla", 0.4); ("truc", 0.6)]);
  print_string"Tout les tests ont réussi !\n";;