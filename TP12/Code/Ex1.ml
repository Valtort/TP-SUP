type 'a ab =
  | V (*Vide*)
  | N of 'a *'a ab * 'a ab (*Noeuds: elem, gauche, droite*)
(*Exemple*)
let t =
N(3,
  N(5,
    V,
      N(8,
      V,
      V
    )
  ),
  N(7,
    V,
    V
  )
)

let t2 = 
N((2,4),
  N((3,5),
  V,
  N((4,8),V,V)
  ),
  N((1,9),V,V)

)

let t3 = 
  N((1,4),
    N((1,5),
    V,
    N((1,8),V,V)
    ),
    N((1,9),V,V)
  
  )
(*Taille a renvoie le nombre total de noeuds de a*)
let rec taille (a:'a ab) : int =
  match a with
  | V -> 0
  | N(x,g,d) -> 1 + taille g + taille d

let test_taille () =
  assert (taille V=0);
  assert (taille t = 4);
  assert ((taille (N(2,t,t)))=9)

(*Q1*)
(*Fonction auxiliaire qui donne le max entre a et b*)
let rec max (a:'a) (b:'a) : 'a =
  if a <= b then b else a

(*Fonction hauteur qui permet de calculer la hauteur d'un arbre binaire*)
let rec hauteur (a:'a ab) : int =
  match a with
  | V -> -1
  | N(_,g,d) -> max (hauteur g) (hauteur d)

let test_hauteur () =
  assert (hauteur V =0);
  assert (hauteur t = 3);
  assert ((hauteur (N(2,t,t)))=4)

(*Q2*)
(*Fonction est_feuille qui determine si un arbre est une feuille*)
let est_feuille (a:'a ab) : bool =
  match a with 
  | N(_,V,V) -> true
  | _ -> false
let test_est_feuille = 
  assert ((est_feuille (N(1,V,V)))=true);
  assert (est_feuille t = false)

(*Fonction feuilles qui comptennt le nb de feuilles*)
let rec feuilles (a:'a ab) : int =
  match a with
  | V -> 0
  | N(_,V,V) -> 1
  | N(_,g,d) -> feuilles g + feuilles d

let test_feuilles =
  assert (feuilles V = 0);
  assert (feuilles (N(1,V,V))=1);
  assert (feuilles t = 2)

(*Q3*)
(*Fonction qui renvoie la valeur d'une etiquette*)
let rec etiquette (a:'a ab) (l: bool list) : 'a =
  match (a,l) with 
  | (V,_) -> failwith("Arbre non valide")
  | (N(e,g,d),[]) -> e
  | (N(e,g,d),x::q) -> 
    if x = true then etiquette d q
  else etiquette g q


let test_etiquette =
  (* assert (etiquette V []= failwith("Arbre non valide")); *)
  assert (etiquette t [true] = 7);
  (* assert (etiquette t [true; true] = failwith("Chemin non valide"));
  assert (etiquette t [false; false] = failwith("Chemin non valide")); *)
  assert (etiquette t [false; true] = 8)

(*Q4*)

(*Fonction etiquette_opt qui renvoie l'etiquette associée a un chemin binaire dans un arbre*)
let rec etiquette_opt (a:'a ab) (l:bool list) : 'a option = 
  match (a,l) with 
  | (V,_) -> None
  | (N(e,g,d),[]) -> Some e
  | (N(e,g,d),x::q) -> 
    if x = true then etiquette_opt d q
  else etiquette_opt g q



let test_etiquette_opt =
  assert (etiquette_opt V []= None);
  assert (etiquette_opt t [true] = Some 7);
  assert (etiquette_opt t [true;true ;true] = None);
  assert (etiquette_opt  t [false; true] = Some 8)



(*Q5*)
(*Fonction print_prefixe qui prend un arbre et affiche ses etiquettes selon le parcours prefixe*)
let rec print_prefixe (a:int ab) : unit =
  match a with
  | V -> ();
  | N(e,g,d) -> print_int(e);
  print_prefixe g ; print_prefixe d

(*Q6*)
(*Fonction qui prennent un arbre et renvoie une liste des etiquettes selon l'ordre postfixe*)
let rec liste_prefixe (a:'a ab) : 'a list =
  match a with
  | V -> []
  | N(e,g,d) -> e::((liste_prefixe g)@(liste_prefixe d))


let test_prefixe =
  assert (liste_prefixe t = [3;5;8;7]);
  assert (liste_prefixe V = [])
(*Fonction qui prennent un arbre et renvoie une liste des etiquettes selon l'ordre infixe*)
let rec liste_infixe (a:'a ab) : 'a list =
  match a with
  | V -> []
  | N(e,g,d) -> ((liste_infixe g)@[e]@(liste_infixe d))

let test_infixe =
  assert (liste_infixe t = [5;8;3;7]);
  assert (liste_infixe V = [])

(*Q7*)
(*Fonction qui liste les etiquettes d'un arbre selon l'ordre post fixe*)
let rec liste_postfixe_aux (a:'a ab) : 'a list =
  match a with
  | V -> []
  | N(e,g,d) -> e::(liste_postfixe_aux d)@(liste_postfixe_aux g)
let liste_postfixe (a:'a ab) : 'a list = List.rev (liste_postfixe_aux a)


let test_postfixe =
  assert (liste_postfixe t = [8;5;7;3]);
  assert (liste_postfixe V = [])



  (*Correction*)

let liste_postfixe a =
  let rec liste_postfixe_rev aa =
    match aa with
    | V -> []
    | N(x,g,d) -> x::(liste_postfixe_rev d )@(liste_postfixe_rev g)
  in liste_postfixe_rev a 
(*Q8*)

(*Liste prefixe sans @*)
let rec liste_prefixe2_aux (a:'a ab) (l:'a list ) : 'a list =
  match a with 
  | V -> l
  | N(e,g,d) -> (liste_prefixe2_aux d (liste_prefixe2_aux g (e::l)))
let liste_prefixe_2 (a:'a ab)= List.rev (liste_prefixe2_aux a [] )

let test_prefixe_2 =
  assert (liste_prefixe_2 t = [3;5;8;7]);
  assert (liste_prefixe_2 V = [])

(*Q10*)
(*Fonction tree_map qui applique une fonction sur chaque noeud*)
let rec tree_map (f: 'a -> 'b) (a : 'a ab) : 'b ab =
  match a with
  | V -> V
  | N(e,g,d) -> N(f e,tree_map f g, tree_map f d)

let test_treemap =
  let f x = x*x in
  assert ((tree_map f V)=V);
  assert ((tree_map f t)=
  N(9,
  N(25,
    V,
      N(64,
      V,
      V
    )
  ),
  N(49,
    V,
    V
  )
))

(*Q11*)
(*Fonction tree_sum qui calcule la somme des entiers contenus dans un arbre*)
let rec tree_sum (a : int ab) : int =
  match a with
  | V -> 0
  | N(e,g,d) -> e + tree_sum g + tree_sum d

let test_treesum =
  assert ((tree_sum V) = 0);
  assert ((tree_sum t) = 23)

(*Q12*)
(*Fonction appartient déterminant si un élément se trouve dans un arbre binaire*)
let rec appartient (x :'a) (a : 'a ab) : bool =
  match a with
  |V -> false
  | N(e,g,d) -> if e = x then true else appartient x g || appartient x d

let test_appartient =
  assert ((appartient 3 t) = true);
  assert ((appartient 2 t) = false);
  assert ((appartient 5 V) = false) 

(*Q14*)
(*Fonction assoc_opt qui prend une clée k et recherche une valeur associé a cette clé, si il n'y en pas, on renvoie none*)
let rec assoc_opt (k: 'k) (a: ('k * 'v )ab) : 'v option =
  match a with
  | V -> None
  | N((ek,ev),g,d) -> if ek = k then Some ev 
  else if assoc_opt k g = None then assoc_opt k d
  else assoc_opt k g

  
let test_assoc_opt = 
  assert ((assoc_opt 1 t2)= Some 9);
  assert ((assoc_opt 5 V)= None);
  assert ((assoc_opt 7 t2)= None)

(*Q15*)
(*Fonction assoc_all qui prend un elem k et un arbre de couple clé-valeur et renvoye la liste de toute les valeurs de v tq k,v est une etiquette*)
let rec assoc_all (k:'k) (a: ('k*'v) ab) (acc : 'v list): 'v list =
  match a with 
  | V -> acc
  | N((ek,ev),g,d) -> if ek = k then 
  if assoc_all k g (ev::acc) = ev::acc 
  then assoc_all k d (ev::acc) 
  else assoc_all k g (ev::acc)
else if assoc_all k g (acc) = acc 
  then assoc_all k d (acc) 
  else assoc_all k g (acc)

let test_assoc_all =
  assert ((assoc_all 1 t3 []) = [4;5;8;9]);
  assert ((assoc_all 2 t3 []) = []);
  assert ((assoc_all 5 V []) = [])