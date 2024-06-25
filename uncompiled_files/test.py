from pandas import DataFrame

df = DataFrame(columns=["modellname", "herstellername", "ps"])
df.loc[0]=["911", "Porsche", 370]
df.loc[1]=["Testarossa", "Ferrari", 390]
print(df.loc[0].ps)
