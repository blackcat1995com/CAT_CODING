import pymongo

client = pymongo.MongoClient('127.0.0.1', 27017)

db = client['school']

# db.create_collection('student')

collections = db.list_collection_names()

print(collections)

databases = client.list_database_names()

print(databases)
