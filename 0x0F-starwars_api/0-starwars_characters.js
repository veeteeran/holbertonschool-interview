#!/usr/bin/node

const request = require('request');
const movieID = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + movieID + '/';

request.get(url, async (error, response, body) => {
  if (error) { return; }

  const data = JSON.parse(body);

  const getName = charURLS => {
    const promise = new Promise((resolve, reject) => {
      request.get(charURLS, (error, response, body) => {
        if (error) { reject(error); } else { resolve(body); }
      });
    });
    return promise;
  };

  for (let i = 0; i < (data.characters).length; i++) {
    const result = await getName(data.characters[i]);
    console.log(JSON.parse(result).name);
  }
});
