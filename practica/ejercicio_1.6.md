## Ejercicio 1.6
Escribe los procedimientos inp_to_ndc, ndc_to_user, user_to_ndc y ndc_to_dc que transforman datos entre los diversos sistemas de coordenadas, como se muestra en la Figura 1.3. Repita el ejercicio asumiendo que el intervalo de variación del sistema NDC va de:

#### (i) -1 a +1 (coordenadas normalizadas centras)
* inp_to_ndc
```bash
      ndcx = dcx / ndhm1;
      ndcy = dcy / ndvm1;
```
* ndc_to_user
```bash
      x = ( ndcx * (xmax - xmin) ) + xmin;
      y = ( ndcy * (ymax - ymin) ) + ymin;
```

	  reemplazando...
    
    
```bash
      x = ( ndcx * (1 - (-1)) ) + (-1);
      y = ( ndcy * (1 - (-1)) ) + (-1);
```
* user_to_ndc
```bash
      ndcx = (x - xmin) / (xmax - xmin);
      ndcy = (y - ymin) / (ymax - ymin);
```
	  reemplazando...
```bash
      ndcx = (x - (-1)) / (1 - (-1));
      ndcy = (y - (-1)) / (1 - (-1));
```
* ndc_to_dc
```bash
      dcx = round(ndcx * ndhm1);
      dcy = round(ndcy * ndvm1);
```
#### (ii) 0 a 100

* inp_to_ndc
```bash
      ndcx = dcx / ndhm1;
      ndcy = dcy / ndvm1;
```
* ndc_to_user
```bash
      x = ( ndcx * (xmax - xmin) ) + xmin;
      y = ( ndcy * (ymax - ymin) ) + ymin;
```

	  reemplazando...
    
```bash
      x = ( ndcx * (100 - (0)) ) + (0);
      y = ( ndcy * (100 - (0)) ) + (0);
```
* user_to_ndc
```bash
      ndcx = (x - xmin) / (xmax - xmin);
      ndcy = (y - ymin) / (ymax - ymin);
```
	  reemplazando...
```bash
      ndcx = (x - (0)) / (100 - (0));
      ndcy = (y - (0)) / (100 - (0));
```
* ndc_to_dc
```bash
      dcx = round(ndcx * ndhm1);
      dcy = round(ndcy * ndvm1);
```
