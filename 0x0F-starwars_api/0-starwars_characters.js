#!/usr/bin/node

const request = require('request');

const apiurl = 'https://swapi.dev/api/films/' + process.argv.slice(2) + '/';

const promises = [];

request(apiurl, function (error, response, body) {
  if (error) {
  }
  const characters = JSON.parse(body).characters;
  for (const url in characters) {
    promises.push(new Promise(function (resolve) {
      request(characters[url], function (error, response, body) {
        if (error) {
        }
        resolve(JSON.parse(body).name);
      });
    }));
  }
  Promise.all(promises).then(function (names) {
    for (const name in names) {
      console.log(names[name]);
    }
  });
});
