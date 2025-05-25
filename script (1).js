
db.Catalog.createIndex(
{ title: "text", description: "text" },
{ name: "TextIndex" } )

db.Catalog.insertMany([{
title: "Wireless Bluetooth Headphones",
description: "High quality sound, noise cancellation, long battery life.",
category: "Electronics",
price: 49.99 },
{
title: "Bluetooth Speaker",
description: "Portable speaker with loud bass and clear sound.",
category: "Electronics",
price: 29.99 },
{
title: "Cookbook: Healthy Recipes",
description: "Over 100 delicious and healthy recipes for weight loss.", 
category: "Books",
price: 19.99 }])

db.Catalog.aggregate([ {
$match: {
$text: { $search: "bluetooth" }
} },
{
$addFields: {
score: { $meta: "textScore" } }
}, {
$sort: { score: -1 } },
 
{
$project: {
_id: 0,
title: 1, description: 1, category: 1, price: 1, score: 1
} }
]).pretty()

db.Catalog.aggregate([ {
$match: {
$text: { $search: "bluetooth" }
} },
{
$addFields: {
score: { $meta: "textScore" } }
}, {
$match: {
  
category: "Electronics",
price: { $lt: 50 } }
}, {
$sort: { score: -1 } },
{
$project: {
_id: 0,
title: 1, description: 1, category: 1, price: 1, score: 1
} }
]).pretty()