from headers import client

db = client['school']

bson_list = [
    {'name': 'Allen', 'age': 10, 'gender': True},
    {'name': 'Jack', 'age': 12, 'gender': True},
    {'name': 'Alice', 'age': 9, 'gender': False}
]

db.student.insert_many(bson_list)

res = list(db.student.find())
print(res)
